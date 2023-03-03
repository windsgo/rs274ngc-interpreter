add_library(inifile OBJECT inifile.cc)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

target_include_directories(inifile PRIVATE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include/rs274>
)
