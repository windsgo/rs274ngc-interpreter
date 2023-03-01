add_executable(sai driver.cc saicanon.cc)

add_dependencies(sai rs274)
add_dependencies(sai inifile)
add_dependencies(sai pythonplugin)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

target_include_directories(sai SYSTEM PUBLIC
    ${Python2_INCLUDE_DIRS} 
    ${Boost_INCLUDE_DIR} 
    ${PROJECT_SOURCE_DIR}/nml_intf/
    ${PROJECT_SOURCE_DIR}/motion/
    ${PROJECT_SOURCE_DIR}/pythonplugin/
    ${PROJECT_SOURCE_DIR}/rtapi/
    ${PROJECT_SOURCE_DIR}/inifile/
    ${PROJECT_SOURCE_DIR}/hal/
    ${PROJECT_SOURCE_DIR}/rs274ngc/
    ${PROJECT_SOURCE_DIR}
)
target_link_libraries(sai rs274 pythonplugin inifile ${Boost_LIBRARIES} ${Python2_LIBRARIES} readline)