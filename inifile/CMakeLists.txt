add_library(inifile OBJECT inifile.cc)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

target_include_directories(inifile PRIVATE
    ${PROJECT_SOURCE_DIR}
)