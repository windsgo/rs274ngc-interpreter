function(print_variable x)
    list(LENGTH ${x} len)
    if (${len} GREATER 1 AND ${len} LESS 10)
        message(STATUS "[*PRINT*] \${${x}}:")
        foreach(_x ${${x}})
            message(STATUS "          ${_x}")
        endforeach()
    else()
        message(STATUS "[*PRINT*] \${${x}}:${${x}}")
    endif()
endfunction()