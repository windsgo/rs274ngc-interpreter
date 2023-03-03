add_executable(sai driver.cc saicanon.cc builtin_modules.cc)

add_dependencies(sai rs274)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

target_include_directories(sai PUBLIC
    ${PROJECT_SOURCE_DIR}/nml_intf/
    ${PROJECT_SOURCE_DIR}/inifile/
    ${PROJECT_SOURCE_DIR}/rs274ngc/
    ${PROJECT_SOURCE_DIR}
)
target_link_libraries(sai PUBLIC
    rs274
    Boost::python
    Python2::Python
    readline
)