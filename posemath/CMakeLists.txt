aux_source_directory(. POSEMATH_SRC)
add_library(posemath OBJECT ${POSEMATH_SRC})
set(CMAKE_INCLUDE_CURRENT_DIR ON)

target_include_directories(posemath PRIVATE
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/rtapi/
)