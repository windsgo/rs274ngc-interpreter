/* config.h.in.  Generated from configure.ac by autoheader.  */

/********************************************************************
* Description: config.h
*
*	Common defines used in many emc2 source files.
*       To add to this file, edit Section 4.1 in configure.ac
*       and then run autoheader.
*
* Author: Autogenerated by autoheader
* License: LGPL Version 2
* System: Linux
*    
* Copyright (c) 2004 All rights reserved.
********************************************************************/
#ifndef EMC2_CONFIG_H
#define EMC2_CONFIG_H

/* LINELEN is used throughout for buffer sizes, length of file name strings,
   etc. Let's just have one instead of a multitude of defines all the same. */
#define LINELEN 255
/* Used in a number of places for sprintf() buffers. */
#define BUFFERLEN 80

#define MM_PER_INCH 25.4
#define INCH_PER_MM (1.0/25.4)


/* Directory for binaries */
#undef EMC2_BIN_DIR

/* Directory for configuration files */
#undef EMC2_CONFIG_DIR

/* Default nml file */
#undef EMC2_DEFAULT_NMLFILE

/* Default nml file */
#ifndef EMC2_DEFAULT_TOOLTABLE
#define EMC2_DEFAULT_TOOLTABLE __RS274_ROOT__ "sim.tbl" // lyf
#endif

/* Directory for help files */
#undef EMC2_HELP_DIR

/* Prefix or RIP directory */
#ifndef EMC2_HOME
#define EMC2_HOME "" // lyf
#endif

/* Directory for images */
#undef EMC2_IMAGE_DIR

/* Directory for tcl translation files */
#undef EMC2_LANG_DIR

/* Directory for nc files */
#undef EMC2_NCFILES_DIR

/* Directory for po/mo translation files */
#undef EMC2_PO_DIR

/* Directory of realtime system */
#undef EMC2_RTLIB_DIR

/* Directory for tcl scripts */
#undef EMC2_TCL_DIR

/* define if the Boost::Python headers and library are available */
#undef HAVE_BOOST_PYTHON

/* Define to 1 if clock_nanosleep is available (in -lc or -lrt) */
#undef HAVE_CLOCK_NANOSLEEP

/* define if the compiler supports basic C++11 syntax */
#undef HAVE_CXX11

/* Define to 1 if you have the <GL/glu.h> header file. */
#undef HAVE_GL_GLU_H

/* Define to 1 if you have the <GL/gl.h> header file. */
#undef HAVE_GL_GL_H

/* Define to 1 if you have the <inttypes.h> header file. */
#undef HAVE_INTTYPES_H

/* Define to 1 if you have the `GL' library (-lGL). */
#undef HAVE_LIBGL

/* Define to 1 if you have the `intl' library (-lintl). */
#undef HAVE_LIBINTL

/* Define to 1 if you have the <libintl.h> header file. */
#undef HAVE_LIBINTL_H

/* define if the libmodbus3 headers and library are available */
#undef HAVE_LIBMODBUS3

/* Define to 1 if you have the `tirpc' library (-ltirpc). */
#undef HAVE_LIBTIRPC

/* define if the libusb-1.0 headers and library are available */
#undef HAVE_LIBUSB10

/* Define to 1 if you have the `Xinerama' library (-lXinerama). */
#undef HAVE_LIBXINERAMA

/* Define to 1 if you have the <locale.h> header file. */
#undef HAVE_LOCALE_H

/* Define to 1 if getopt has the BSD 'optreset' extension */
#undef HAVE_OPTRESET

/* Define to 1 if you have the 'readline' library (-lreadline) and required
   headers */
#undef HAVE_READLINE

/* Define to 1 if you have the <readline/history.h> header file. */
#undef HAVE_READLINE_HISTORY_H

/* Define to 1 if you have the <readline/readline.h> header file. */
#undef HAVE_READLINE_READLINE_H

/* Define to 1 if you have the `semtimedop' function. */
#undef HAVE_SEMTIMEDOP

/* Define to 1 if you have the `setlocale' function. */
#undef HAVE_SETLOCALE

/* Define to 1 if you have the <stdint.h> header file. */
#undef HAVE_STDINT_H

/* Define to 1 if you have the <stdio.h> header file. */
#undef HAVE_STDIO_H

/* Define to 1 if you have the <stdlib.h> header file. */
#undef HAVE_STDLIB_H

/* Define to 1 if you have the <strings.h> header file. */
#undef HAVE_STRINGS_H

/* Define to 1 if you have the <string.h> header file. */
#undef HAVE_STRING_H

/* Define to 1 if you have the <sys/io.h> header file. */
#undef HAVE_SYS_IO_H

/* Define to 1 if you have the <sys/stat.h> header file. */
#undef HAVE_SYS_STAT_H

/* Define to 1 if you have the <sys/types.h> header file. */
#undef HAVE_SYS_TYPES_H

/* Define to 1 if you have <sys/wait.h> that is POSIX.1 compatible. */
#undef HAVE_SYS_WAIT_H

/* Define to 1 if you have the <tcl.h> header file. */
#undef HAVE_TCL_H

/* Define to 1 if you have the <tk.h> header file. */
#undef HAVE_TK_H

/* Define to 1 if you have the <unistd.h> header file. */
#undef HAVE_UNISTD_H

/* Define to 1 if you have the <X11/extensions/Xinerama.h> header file. */
#undef HAVE_X11_EXTENSIONS_XINERAMA_H

/* Define to 1 if you have the <X11/Xmu/Xmu.h> header file. */
#undef HAVE_X11_XMU_XMU_H

/* Define to 1 if linux/hidraw.h is usable and defines HIDIOCGRAWINFO */
#undef HIDRAW_H_USABLE

/* Define to the library that dlopen comes from, if it is not a part of libc
   */
#undef LIBDL

/* Extension for realtime modules */
#undef MODULE_EXT

/* Define to the address where bug reports for this package should be sent. */
#undef PACKAGE_BUGREPORT

/* Define to the full name of this package. */
#undef PACKAGE_NAME

/* Define to the full name and version of this package. */
#undef PACKAGE_STRING

/* Define to the one symbol short name of this package. */
#undef PACKAGE_TARNAME

/* Define to the home page for this package. */
#undef PACKAGE_URL

/* Define to the version of this package. */
#ifndef PACKAGE_VERSION
#define PACKAGE_VERSION "2.8.4" // lyf
#endif

/* Required kernel version */
#undef RTAPI_KERNEL_VERSION

/* Realtime system is RTAI */
#undef RTAPI_RTAI

/* Realtime system is userspace */
#undef RTAPI_USPACE

/* Directory of the installed realtime system */
#undef RTDIR

/* Define to 1 if all of the C90 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#undef STDC_HEADERS

/* Define if uspace realtime should optionally support RTAI LXRT */
#undef USPACE_RTAI

/* Define if uspace realtime should optionally support Xenomai */
#undef USPACE_XENOMAI

/* Define to 1 if the X Window System is missing or not being used. */
#undef X_DISPLAY_MISSING

/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif


#endif

