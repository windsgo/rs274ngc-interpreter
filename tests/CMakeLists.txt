add_executable(test test.cc)
add_dependencies(test rs274)

target_compile_options(test PUBLIC -Wno-return-type)

target_include_directories(test PUBLIC
    ${Python2_INCLUDE_DIRS} 
    ${Boost_INCLUDE_DIR} 
    ${PROJECT_SOURCE_DIR}/nml_intf/
    ${PROJECT_SOURCE_DIR}/inifile/
    ${PROJECT_SOURCE_DIR}/rs274ngc/
    ${PROJECT_SOURCE_DIR}
)

target_link_libraries(test rs274 ${Boost_LIBRARIES} ${Python2_LIBRARIES} )
