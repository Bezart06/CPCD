cmake_minimum_required(VERSION 3.10)

project(CPCD)

if (WIN32)
    set(OS_TYPE "Windows")
elseif (WIN64)
    set(OS_TYPE "Windows")
elseif (UNIX)
    set(OS_TYPE "Linux")
elseif (LINUX)
    set(OS_TYPE "Linux")
endif ()

add_executable(CPCD WIN32 main.cpp)

if(OS_TYPE STREQUAL "Windows")
    set_target_properties(CPCD PROPERTIES OUTPUT_NAME "CPCD_executable")
    target_link_libraries(CPCD -static-libgcc -static-libstdc++ -static)
elseif(OS_TYPE STREQUAL "Linux")
    set_target_properties(CPCD PROPERTIES OUTPUT_NAME "CPCD_executable")
endif()

if(OS_TYPE STREQUAL "Windows")
    add_custom_command(TARGET CPCD
            POST_BUILD
            COMMAND powershell -Command "Start-Process cmd.exe -Verb RunAs -ArgumentList '/c', $<TARGET_FILE:CPCD>"
    )
elseif(OS_TYPE STREQUAL "Linux")
    add_custom_command(TARGET CPCD
            POST_BUILD
            COMMAND sudo chmod +x $<TARGET_FILE:CPCD>
            COMMAND sudo $<TARGET_FILE:CPCD>
    )
endif()
