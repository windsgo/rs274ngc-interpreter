add_library(pythonplugin OBJECT python_plugin.cc)

add_dependencies(pythonplugin inifile)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

target_include_directories(pythonplugin PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/nml_intf>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/rtapi>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/inifile>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/rs274>
)
target_link_libraries(pythonplugin PUBLIC
    Boost::python
    Python2::Python 
    inifile
)