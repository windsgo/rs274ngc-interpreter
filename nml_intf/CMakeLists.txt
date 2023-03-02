aux_source_directory(. NML_INTF_SRC)
add_library(nml_intf OBJECT ${NML_INTF_SRC})
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_dependencies(nml_intf posemath)

target_include_directories(nml_intf PUBLIC
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/posemath/
    ${PROJECT_SOURCE_DIR}/rtapi/
    ${PROJECT_SOURCE_DIR}/motion/
)

target_link_libraries(nml_intf posemath)