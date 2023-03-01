add_library(pythonplugin OBJECT python_plugin.cc)

add_dependencies(pythonplugin inifile)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

target_include_directories(pythonplugin SYSTEM PUBLIC
    ${Python2_INCLUDE_DIRS} 
    ${Boost_INCLUDE_DIR} 
    ${PROJECT_SOURCE_DIR}/nml_intf/
    ${PROJECT_SOURCE_DIR}/rtapi/
    ${PROJECT_SOURCE_DIR}/inifile/
    ${PROJECT_SOURCE_DIR}
)
target_link_libraries(pythonplugin ${Boost_LIBRARIES} ${Python2_LIBRARIES} inifile)