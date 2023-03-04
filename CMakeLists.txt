## cmake version
cmake_minimum_required(VERSION 3.14)

## project define
project(rs274 LANGUAGES CXX C VERSION 1.0.0)

## BUILD_TYPE
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

## include function print_variable()
include(${PROJECT_SOURCE_DIR}/cmake/printv.cmake)

# install 相关
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
print_variable(CMAKE_INSTALL_PREFIX)
print_variable(CMAKE_INSTALL_LIBDIR)
print_variable(CMAKE_INSTALL_INCLUDEDIR)
print_variable(CMAKE_INSTALL_BINDIR)

## compile definitions
# 指定项目源码根目录，便于调试文件输入
add_compile_definitions(__RS274_ROOT__="${PROJECT_SOURCE_DIR}/")
# 定义ULAPI，见rtapi_*.h
add_compile_definitions(ULAPI)
# 使用snprintf代替rtapi_snprintf通过编译，使用标准库的snprintf
add_compile_definitions(rtapi_snprintf=snprintf) # pass rtapi compile

## cmake 编译选项
# 导出compile_commands.json供vscode或clangd服务静态检查、补全
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# 位置无关代码，相当于-fPIC
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
# 编译输出的动态库、静态库、可执行文件路径
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

## 依赖库查找
# 指定BOOST_ROOT，查找对应版本的Boost，必须对应boost_python2.7
if (NOT BOOST_ROOT)
    set(BOOST_ROOT $ENV{HOME}/Boost_1_79_0/lib/cmake/)
endif()
print_variable(BOOST_ROOT)

# Boost::python
find_package(Boost COMPONENTS python REQUIRED)
print_variable(Boost_VERSION)
print_variable(Boost_FOUND)
print_variable(Boost_INCLUDE_DIR)
print_variable(Boost_INCLUDE_DIRS)
print_variable(Boost_LIBRARY_DIRS)
print_variable(Boost_LIBRARIES)
print_variable(Boost_PYTHON_VERSION)

# confirm boost_python version
if(${Boost_PYTHON_VERSION} EQUAL 2.7)
    message(STATUS  "Boost_PYTHON_VERSION:${Boost_PYTHON_VERSION} is 2.7")
else()
    message(FATAL_ERROR "Boost_PYTHON_VERSION:${Boost_PYTHON_VERSION} is not to 2.7")
endif()

# Python2::Development
find_package(Python2 REQUIRED Development REQUIRED)
print_variable(Python2_VERSION)
print_variable(Python2_INCLUDE_DIRS)
print_variable(Python2_LIBRARIES)

## find every header
set(RS274_SUB_DIRS posemath inifile motion nml_intf pythonplugin rs274ngc rtapi)
foreach(sub_dir ${RS274_SUB_DIRS})
    file(GLOB_RECURSE RS274_SUBDIR_INCLUDE_FILES 
        "${sub_dir}/*.h" 
        "${sub_dir}/*.hh" 
        "${sub_dir}/*.hpp"
    )
    list(APPEND RS274_INCLUDE_FILES ${RS274_SUBDIR_INCLUDE_FILES})
endforeach()
# 转换为相对路径
foreach(_x ${RS274_INCLUDE_FILES})
    file(RELATIVE_PATH tmp ${PROJECT_SOURCE_DIR} ${_x})
    list(POP_FRONT RS274_INCLUDE_FILES ${_x})
    list(APPEND RS274_INCLUDE_FILES ${tmp})
endforeach()
list(APPEND RS274_INCLUDE_FILES config.h)

## 添加子文件夹
# object libs
add_subdirectory(posemath)
add_subdirectory(nml_intf)
add_subdirectory(inifile)
add_subdirectory(pythonplugin)

# shared lib which links all the above
add_subdirectory(rs274ngc) # librs274.so

# binaries
add_subdirectory(sai)
add_subdirectory(tests)

print_variable(RS274_INCLUDE_FILES)

## 配置find_package

# Note: INSTALL_RPATH ${Boost_LIBRARY_DIRS}
# What:
#   Set `INSTALL_RPATH` property to let the INSTALLED library have the search path
#   of libboost_python27.so.1.0 at runtime
# Why:
#   When an excutable or another library links to the INSTALLED `rs274` dynamically,
#   even though the excutable may link to libboost_python27,
#   `librs274.so` need to know where to search for libboost_python27 itself !
# Mention:
#   This should be done, since libboost_python27 is often not a system lib,
#   it needs to be set according to different systems.
#   So this lib is recommanded to compile each time on a new operating system.
#   However, it can also be used if LD_LIBRARY_PATH is set proporly 
#   or the libboost_python27 path is included in /etc/ld.so.conf.
#   I do this just to make runtime easier for compile test.
set_target_properties(rs274
    PROPERTIES PUBLIC_HEADER "${RS274_INCLUDE_FILES}"
    INSTALL_RPATH ${Boost_LIBRARY_DIRS}
)

install(
    TARGETS rs274
    EXPORT rs274Targets
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/rs274
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    # INCLUDES DESTINATION include/rs274
)
install(
    EXPORT rs274Targets
    NAMESPACE rs274::
    FILE rs274Targets.cmake
    DESTINATION lib/cmake/rs274
)

configure_package_config_file(cmake_modules/rs274Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/rs274Config.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/rs274
)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/rs274ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/rs274Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/rs274ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/rs274
)

