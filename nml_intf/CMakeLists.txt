aux_source_directory(. NML_INTF_SRC)
add_library(nml_intf OBJECT ${NML_INTF_SRC})
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_dependencies(nml_intf posemath)

target_include_directories(nml_intf PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/motion>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/rtapi>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/posemath>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/rs274>
)

target_link_libraries(nml_intf PUBLIC
    posemath
)