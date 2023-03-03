# Use this virtual Makefile to build easily
# especially when you use vim

build_dir := build
install_dir := install

# choose your own boost root dir(need boost_python2.7)
boost_root := ${HOME}/Boost_1_79_0/lib/cmake/

default: configure build

# Note: Currently, CMAKE_INSTALL_PREFIX is hard coded in CMakeLists.txt for debug convenience
configure:
	cmake -B ${build_dir} -DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_INSTALL_PREFIX=${install_dir} \
	-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
	-DBOOST_ROOT=${boost_root}

build: configure
	cmake --build ${build_dir} -j16

install: configure build
	cmake --install ${build_dir}

uninstall:
	rm -rf ${install_dir}

clean:
	rm -rf ${build_dir}


.PHONY: default configure build install uninstall clean