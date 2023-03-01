cmake_minimum_required(VERSION 3.14)

project(rs274 LANGUAGES CXX C)

include(${PROJECT_SOURCE_DIR}/cmake/printv.cmake)

add_compile_definitions(__RS274_ROOT__="${PROJECT_SOURCE_DIR}/")

add_compile_definitions(EMC2_DEFAULT_TOOLTABLE="${PROJECT_SOURCE_DIR}/sim.tbl")
add_compile_definitions(ULAPI)
add_compile_definitions(rtapi_snprintf=snprintf) # pass rtapi compile

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

set(BOOST_ROOT $ENV{HOME}/Boost_1_79_0/lib/cmake/)
print_variable(Boost_DIR)

find_package(Boost COMPONENTS python REQUIRED)
print_variable(Boost_VERSION)
print_variable(Boost_FOUND)
print_variable(Boost_INCLUDE_DIR)
print_variable(Boost_LIBRARIES)
print_variable(Boost_PYTHON_VERSION)

find_package(Python2 REQUIRED Development REQUIRED)
print_variable(Python2_VERSION)
print_variable(Python2_INCLUDE_DIRS)
print_variable(Python2_LIBRARIES)

# find_package(Python3 COMPONENTS Development REQUIRED)
# print_variable(Python3_VERSION)
# print_variable(Python3_INCLUDE_DIRS)
# print_variable(Python3_LIBRARIES)

# add_subdirectory(rtapi)
add_subdirectory(inifile)
add_subdirectory(pythonplugin)
add_subdirectory(rs274ngc)
add_subdirectory(sai)

