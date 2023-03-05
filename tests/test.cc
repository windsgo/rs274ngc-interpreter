// #include <Python.h> // must be first header
#include <iostream>
#include "rs274ngc.hh"
#include "canon.hh"
#include "rs274ngc_return.hh"

// static void read_execute(InterpBase *b, const char *line) {
//     fprintf(stderr, "> %s\n", line);
//     int r = b->read(line);
//     std::cout << b->execute() << std::endl;
//     std::cout << b->line() << std::endl;
//     std::cout << b->line_length() << std::endl;
//     char x[256];
//     std::cout << b->line_text(x, sizeof(x)) << std::endl;
// }

class Sp {
public:
    Sp() : _sp_s(), _sp_e() {

    }
    Sp(std::string sp_s, std::string sp_e) : _sp_s(std::move(sp_s)), _sp_e(std::move(sp_e)) {
        std::cout << _sp_s <<  std::endl;
    }
    ~Sp() {
        std::cout << _sp_e << std::endl;
    }
private:
    std::string _sp_s;
    std::string _sp_e;
};

#define _P \
    std::cout << "\t[FUNCTION-AUTO-PRINT]" << __PRETTY_FUNCTION__ << std::endl;

static void func_1(int m, double p, double q) {
    std::cout << "user func_1(): " 
        << " m:" << m 
        << " p:" << p 
        << " q:" << q << std::endl;
    return ;
}

#include <memory>
#include "rs274ngc_interp.hh"
static void test_1() {

    // InterpBase *b = makeInterp();
    auto b = std::make_unique<Interp>(); // allow auto delete

    USER_DEFINED_FUNCTION_ADD(func_1, 1);
    b->init();

    b->open(__RS274_ROOT__ "test.ngc");

    while(true) {
        Sp s;      
        int read_ret = b->read();
        // std::cout << "read ret:" << read_ret << std::endl;
        if (read_ret != 0) break;
        // char x[256];
        // std::cout << "line:"<< b->line() << "\ncontext:" << b->line_text(x, sizeof(x)) << std::endl;
        // memset(x, 0, sizeof(x));
        // std::cout << "command:" << b->command(x, sizeof(x)) << std::endl;

        // std::cout << b->line_length() << std::endl;

        // int execute_ret = b->execute();
        // std::cout << "execute_ret:" << execute_ret << std::endl;
        // if (execute_ret != 0) break;
    }

    std::cout << "----------read and execute-----------\n" << std::endl;

    b->init();
    b->open(__RS274_ROOT__ "test.ngc");
    while (true) {
        Sp s;
        {
            Sp s("---read output start---", "---read output end---");
            int r = b->read();
            std::cout << "r:" << r << std::endl;
            if (r != INTERP_ENDFILE && r != INTERP_OK) {
                char *dbf = (char*)(alloca(256));
                std::cout << "**error: "<< b->error_text(r, dbf, 256) << std::endl;
                break;
            }
        }
        char x[256];
        std::cout << "line:"<< b->line() << "\ncontext:" << b->line_text(x, sizeof(x)) << std::endl;
        int exec_ret;
        {
            Sp s("---exec output start---", "---exec output end---");
            exec_ret = b->execute();
        }
        // std::cout << "exec ret:" << exec_ret << std::endl;
        if (exec_ret != 0) 
        {
            b->close();
            break;
        }

        // memset(x, 0, sizeof(x));
        // std::cout << "command:" << b->command(x, sizeof(x)) << std::endl;
    }
    
    char x[256];
    std::cout << b->file_name(x, sizeof(x)) << std::endl;

    b->exit();

    // read_execute(b, "(this is a comment)");
    // read_execute(b, "G0X0Y0");
    // read_execute(b, "F100");
    // read_execute(b, "G5.2 X3.53   Y-1.50   P2");
    // read_execute(b, "     X5.33   Y-11.01  P1");
    // read_execute(b, "     X3.52   Y-24.00  P1");
    // read_execute(b, "     X0.0    Y-29.56  P1");
    // read_execute(b, "G5.3");
    // read_execute(b, "(second comment)");
    // read_execute(b, "M2");


    // delete b;
}


static void test_2() {
    auto b = std::make_unique<Interp>(); // allow auto delete
    b->init();
}

int main(int argc, char** argv) {
    test_1();
    return 0;
}

// this is junk that you have to define in exactly this way because of how mah
// implemented the python "remap" functionality of the interpreter
// (and it needs Python.h for the definition of struct inttab)
int _task = 0;
char _parameter_file_name[LINELEN];
// extern "C" void initinterpreter();
// extern "C" void initemccanon();
// extern "C" struct _inittab builtin_modules[];
// struct _inittab builtin_modules[] = {
//     { (char *) "interpreter", initinterpreter },
//     { (char *) "emccanon", initemccanon },
//     { NULL, NULL }
// };

// everything below here is stuff that needs a real implementation, not a dummy
// one
void INIT_CANON() {
    std::cout << "Init Canon" << std::endl;
}
void SET_G5X_OFFSET(int origin,
                           double x, double y, double z,
                           double a, double b, double c,
                           double u, double v, double w) {_P}
void SET_G92_OFFSET(double x, double y, double z,
                           double a, double b, double c,
                           double u, double v, double w) {_P}
void SET_XY_ROTATION(double t) {_P}
void CANON_UPDATE_END_POINT(double x, double y, double z, 
				   double a, double b, double c,
				   double u, double v, double w) {_P}
void USE_LENGTH_UNITS(CANON_UNITS u) {_P}
void SELECT_PLANE(CANON_PLANE pl) {_P}
void SET_TRAVERSE_RATE(double rate) {_P}
void STRAIGHT_TRAVERSE(int lineno,
                              double x, double y, double z,
			      double a, double b, double c,
                              double u, double v, double w) {_P}
void SET_FEED_RATE(double rate) {_P}
void SET_FEED_REFERENCE(CANON_FEED_REFERENCE reference) {_P}
void SET_FEED_MODE(int spindle, int mode) {_P}
void SET_MOTION_CONTROL_MODE(CANON_MOTION_MODE mode, double tolerance) {_P}
void SET_NAIVECAM_TOLERANCE(double tolerance) {_P}
void SET_CUTTER_RADIUS_COMPENSATION(double radius) {_P}
void START_CUTTER_RADIUS_COMPENSATION(int direction) {_P}
void STOP_CUTTER_RADIUS_COMPENSATION() {_P}
void START_SPEED_FEED_SYNCH(int spindle, double feed_per_revolution, bool velocity_mode) {_P}
void STOP_SPEED_FEED_SYNCH() {_P}
void ARC_FEED(int lineno,
                     double first_end, double second_end,
		     double first_axis, double second_axis, int rotation,
		     double axis_end_point, 
                     double a, double b, double c,
                     double u, double v, double w) {_P}
void STRAIGHT_FEED(int lineno,
                          double x, double y, double z,
                          double a, double b, double c,
                          double u, double v, double w) {
    printf("-> %.1f %.1f\n", x, y);
}
void NURBS_FEED(int lineno, std::vector<CONTROL_POINT> nurbs_control_points, unsigned int k) {
    double u = 0.0;
    unsigned int n = nurbs_control_points.size() - 1;
    double umax = n - k + 2;
    unsigned int div = nurbs_control_points.size()*3;
    std::vector<unsigned int> knot_vector = knot_vector_creator(n, k);
    PLANE_POINT P1;
    while (u+umax/div < umax) {
        PLANE_POINT P1 = nurbs_point(u+umax/div,k,nurbs_control_points,knot_vector);
        STRAIGHT_FEED(lineno, P1.X,P1.Y, 0., 0.,0.,0.,  0.,0.,0.);
        u = u + umax/div;
    }
    P1.X = nurbs_control_points[n].X;
    P1.Y = nurbs_control_points[n].Y;
    STRAIGHT_FEED(lineno, P1.X,P1.Y, 0., 0.,0.,0.,  0.,0.,0.);
    knot_vector.clear();
}
void RIGID_TAP(int lineno,
                      double x, double y, double z, double scale) {_P}
void STRAIGHT_PROBE(int lineno,
                           double x, double y, double z,
                           double a, double b, double c,
                           double u, double v, double w, unsigned char probe_type) {_P}
void STOP() {std::cout << "STOP" << std::endl;}
void DWELL(double seconds) {_P}
void SET_SPINDLE_MODE(int spindle, double r) {_P}
void SPINDLE_RETRACT_TRAVERSE() {_P}
void START_SPINDLE_CLOCKWISE(int spindle, int dir) {_P}
void START_SPINDLE_COUNTERCLOCKWISE(int spindle, int dir) {_P}
void SET_SPINDLE_SPEED(int spindle, double r) {_P}
void STOP_SPINDLE_TURNING(int spindle) {_P}
void SPINDLE_RETRACT() {_P}
void ORIENT_SPINDLE(int spindle, double orientation, int mode) {_P}
void WAIT_SPINDLE_ORIENT_COMPLETE(int spindle, double timeout) {_P}
void LOCK_SPINDLE_Z() {_P}
void USE_SPINDLE_FORCE() {_P}
void USE_NO_SPINDLE_FORCE() {_P}
void SET_TOOL_TABLE_ENTRY(int pocket, int toolno, EmcPose offset, double diameter,
                                 double frontangle, double backangle, int orientation) {_P}
void USE_TOOL_LENGTH_OFFSET(EmcPose offset) {_P}
void CHANGE_TOOL(int slot) {_P}	
void SELECT_TOOL(int tool) {_P}	
void CHANGE_TOOL_NUMBER(int number) {_P}
void START_CHANGE(void) {_P}
void CLAMP_AXIS(CANON_AXIS axis) {_P}
void COMMENT(const char *s) { puts(s); }
void DISABLE_ADAPTIVE_FEED() {_P}
void ENABLE_ADAPTIVE_FEED() {_P}
void DISABLE_FEED_OVERRIDE() {_P}
void ENABLE_FEED_OVERRIDE() {_P}
void DISABLE_SPEED_OVERRIDE(int spindle) {_P}
void ENABLE_SPEED_OVERRIDE(int spindle) {_P}
void DISABLE_FEED_HOLD() {_P}
void ENABLE_FEED_HOLD() {_P}
void FLOOD_OFF() {_P}
void FLOOD_ON() {_P}
void MESSAGE(char *s) {
    std::cout << "[*****Interp Message]" << s << std::endl;
}
void LOG(char *s) {_P}
void LOGOPEN(char *s) {_P}
void LOGAPPEND(char *s) {_P}
void LOGCLOSE() {_P}
void MIST_OFF() {_P}
void MIST_ON() {_P}
void PALLET_SHUTTLE() {_P}
void TURN_PROBE_OFF() {_P}
void TURN_PROBE_ON() {_P}
void UNCLAMP_AXIS(CANON_AXIS axis) {_P}
void NURB_KNOT_VECTOR() {_P}	
void NURB_CONTROL_POINT(int i, double x, double y, double z,
			       double w) {_P}
void NURB_FEED(double sStart, double sEnd) {_P}
void SET_BLOCK_DELETE(bool enabled) {_P}
bool GET_BLOCK_DELETE(void) {_P}
void OPTIONAL_PROGRAM_STOP() {_P}
void SET_OPTIONAL_PROGRAM_STOP(bool state) {_P}
bool GET_OPTIONAL_PROGRAM_STOP() {_P}
void PROGRAM_END() {
    std::cout << "[**PROGRAM_END]" << std::endl;
}
void PROGRAM_STOP() {_P}
void SET_MOTION_OUTPUT_BIT(int index) {_P}
void CLEAR_MOTION_OUTPUT_BIT(int index) {_P}
void SET_AUX_OUTPUT_BIT(int index) {_P}
void CLEAR_AUX_OUTPUT_BIT(int index) {_P}
void SET_MOTION_OUTPUT_VALUE(int index, double value) {_P}
void SET_AUX_OUTPUT_VALUE(int index, double value) {_P
    std::cout << "aux: index:" << index << " value:" << value << std::endl;
}
int WAIT(int index, 
		int input_type, 
	        int wait_type, 
                double timeout) {_P} 
int UNLOCK_ROTARY(int line_no, int axis) {_P}
int LOCK_ROTARY(int line_no, int axis) {_P}
double GET_EXTERNAL_FEED_RATE() {_P}
int GET_EXTERNAL_FLOOD() {_P}
CANON_UNITS GET_EXTERNAL_LENGTH_UNIT_TYPE() {return CANON_UNITS_MM;}
double GET_EXTERNAL_LENGTH_UNITS() {_P}
double GET_EXTERNAL_ANGLE_UNITS() {_P return 1.0;}
int GET_EXTERNAL_MIST() {_P}
CANON_MOTION_MODE GET_EXTERNAL_MOTION_CONTROL_MODE() {_P}
double GET_EXTERNAL_MOTION_CONTROL_TOLERANCE() {_P}

extern void SET_PARAMETER_FILE_NAME(const char *name) {_P
  strncpy(_parameter_file_name, name, PARAMETER_FILE_NAME_LENGTH);
}
void GET_EXTERNAL_PARAMETER_FILE_NAME(char *file_name, int max_size) {
    _P
        // Paranoid checks
    if (0 == file_name)
	return;

    if (max_size < 0)
	return;

  if (strlen(_parameter_file_name) < (size_t)max_size)
    strcpy(file_name, _parameter_file_name);
  else
    file_name[0] = 0;
}
CANON_PLANE GET_EXTERNAL_PLANE() {_P}
double GET_EXTERNAL_POSITION_A() {_P}
double GET_EXTERNAL_POSITION_B() {_P}
double GET_EXTERNAL_POSITION_C() {_P}
double GET_EXTERNAL_POSITION_X() {_P}
double GET_EXTERNAL_POSITION_Y() {_P}
double GET_EXTERNAL_POSITION_Z() {_P}
double GET_EXTERNAL_POSITION_U() {_P}
double GET_EXTERNAL_POSITION_V() {_P}
double GET_EXTERNAL_POSITION_W() {_P}
double GET_EXTERNAL_PROBE_POSITION_A() {_P}
double GET_EXTERNAL_PROBE_POSITION_B() {_P}
double GET_EXTERNAL_PROBE_POSITION_C() {_P}
double GET_EXTERNAL_PROBE_POSITION_X() {_P}
double GET_EXTERNAL_PROBE_POSITION_Y() {_P}
double GET_EXTERNAL_PROBE_POSITION_Z() {_P}
double GET_EXTERNAL_PROBE_POSITION_U() {_P}
double GET_EXTERNAL_PROBE_POSITION_V() {_P}
double GET_EXTERNAL_PROBE_POSITION_W() {_P}
double GET_EXTERNAL_PROBE_VALUE() {_P}
int GET_EXTERNAL_PROBE_TRIPPED_VALUE() {_P}
int GET_EXTERNAL_QUEUE_EMPTY() {_P}
double GET_EXTERNAL_SPEED(int spindle) {_P}
CANON_DIRECTION GET_EXTERNAL_SPINDLE(int spindle) {_P}
double GET_EXTERNAL_TOOL_LENGTH_XOFFSET() {_P}
double GET_EXTERNAL_TOOL_LENGTH_YOFFSET() {_P}
double GET_EXTERNAL_TOOL_LENGTH_ZOFFSET() {_P}
double GET_EXTERNAL_TOOL_LENGTH_AOFFSET() {_P}
double GET_EXTERNAL_TOOL_LENGTH_BOFFSET() {_P}
double GET_EXTERNAL_TOOL_LENGTH_COFFSET() {_P}
double GET_EXTERNAL_TOOL_LENGTH_UOFFSET() {_P}
double GET_EXTERNAL_TOOL_LENGTH_VOFFSET() {_P}
double GET_EXTERNAL_TOOL_LENGTH_WOFFSET() {_P}
int GET_EXTERNAL_POCKETS_MAX() {_P}
int GET_EXTERNAL_TOOL_SLOT() {_P}
int GET_EXTERNAL_SELECTED_TOOL_SLOT() {_P}
CANON_TOOL_TABLE GET_EXTERNAL_TOOL_TABLE(int pocket) {_P}
int GET_EXTERNAL_TC_FAULT() {_P}
int GET_EXTERNAL_TC_REASON() {_P}
double GET_EXTERNAL_TRAVERSE_RATE() {_P}
int GET_EXTERNAL_FEED_OVERRIDE_ENABLE() {_P}
int GET_EXTERNAL_SPINDLE_OVERRIDE_ENABLE(int spindle) {_P}
int GET_EXTERNAL_ADAPTIVE_FEED_ENABLE() {_P}
int GET_EXTERNAL_FEED_HOLD_ENABLE() {_P}
int GET_EXTERNAL_DIGITAL_INPUT(int index, int def) {_P}
double GET_EXTERNAL_ANALOG_INPUT(int index, double def) {_P}
int GET_EXTERNAL_AXIS_MASK() { return 0b111111; } // select axies to usr
void FINISH(void) {
    std::cout << "[***FINISH]" << std::endl;
}
void ON_RESET(void) {
    std::cout << "[***ON_RESET]" << std::endl;
}
void CANON_ERROR(const char *fmt, ...) {_P}
void PLUGIN_CALL(int len, const char *call) {_P}
void IO_PLUGIN_CALL(int len, const char *call) {_P}
USER_DEFINED_FUNCTION_TYPE
    USER_DEFINED_FUNCTION[USER_DEFINED_FUNCTION_NUM] = {0};

int USER_DEFINED_FUNCTION_ADD(USER_DEFINED_FUNCTION_TYPE func, int num)
{
  if (num < 0 || num >= USER_DEFINED_FUNCTION_NUM) {
    return -1;
  }

  USER_DEFINED_FUNCTION[num] = func;

  return 0;
}

int GET_EXTERNAL_OFFSET_APPLIED() {_P};
EmcPose GET_EXTERNAL_OFFSETS(){_P};