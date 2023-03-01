aux_source_directory(. RS274_SRC)

add_library(rs274 SHARED ${RS274_SRC})

add_dependencies(rs274 pythonplugin)
add_dependencies(rs274 inifile)

target_compile_definitions(rs274 PRIVATE EMC2_HOME="")
target_compile_definitions(rs274 PRIVATE PACKAGE_VERSION="2.8.4")
target_compile_definitions(rs274 PRIVATE RS274_NO_HAL)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

target_include_directories(rs274 PUBLIC
    ${Python2_INCLUDE_DIRS} 
    ${Boost_INCLUDE_DIR} 
    ${PROJECT_SOURCE_DIR}/nml_intf/
    ${PROJECT_SOURCE_DIR}/motion/
    ${PROJECT_SOURCE_DIR}/pythonplugin/
    ${PROJECT_SOURCE_DIR}/rtapi/
    ${PROJECT_SOURCE_DIR}/inifile/
    ${PROJECT_SOURCE_DIR}
)
target_link_libraries(rs274 pythonplugin inifile ${Boost_LIBRARIES} ${Python2_LIBRARIES} )
