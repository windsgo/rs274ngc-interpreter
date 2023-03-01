aux_source_directory(. RTAPI_SOURCE)

print_variable(RTAPI_SOURCE)

add_library(rtapi SHARED ${RTAPI_SOURCE})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

target_include_directories(rtapi PRIVATE
    ${PROJECT_SOURCE_DIR}
)

target_link_libraries(rtapi pthread)