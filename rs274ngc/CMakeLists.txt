aux_source_directory(. RS274_SRC)

add_library(rs274 SHARED ${RS274_SRC})

add_dependencies(rs274 pythonplugin)
add_dependencies(rs274 inifile)
add_dependencies(rs274 posemath)

target_compile_definitions(rs274 PRIVATE EMC2_HOME="")
target_compile_definitions(rs274 PRIVATE PACKAGE_VERSION="2.8.4")
target_compile_definitions(rs274 PRIVATE RS274_NO_HAL)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

target_include_directories(rs274 PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/nml_intf>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/motion>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/pythonplugin>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/rtapi>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/inifile>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/posemath>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/rs274>
)

target_link_libraries(rs274 PRIVATE 
    $<BUILD_INTERFACE:pythonplugin>
    $<BUILD_INTERFACE:inifile>
    $<BUILD_INTERFACE:posemath>
    $<BUILD_INTERFACE:nml_intf>
    Boost::python
    Python2::Python
)
