add_executable(sai driver.cc saicanon.cc builtin_modules.cc)
# 定义EMC2_DEFAULT_TOOLTABLE路径，见config.h
target_compile_definitions(sai
    PRIVATE
    EMC2_DEFAULT_TOOLTABLE="${PROJECT_SOURCE_DIR}/sim.tbl"
)

add_dependencies(sai rs274)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

target_include_directories(sai PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/nml_intf>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/inifile>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/rs274ngc>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    # binary no need INSTALL_INTERFACE
)
target_link_libraries(sai PUBLIC
    rs274
    Boost::python
    Python2::Python
    readline
)

set_target_properties(sai
    PROPERTIES
    INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}
)
install(
    TARGETS sai
    EXPORT saiTargets
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)