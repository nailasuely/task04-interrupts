# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(task04-interrupts C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1

add_executable(task04-interrupts task04-interrupts.c )

pico_set_program_name(task04-interrupts "task04-interrupts")
pico_set_program_version(task04-interrupts "0.1")

# Modify the below lines to enable/disable output over UART/USB
pico_enable_stdio_uart(task04-interrupts 0)
pico_enable_stdio_usb(task04-interrupts 1)

#Converte o .pio para .h
pico_generate_pio_header(task04-interrupts ${CMAKE_CURRENT_LIST_DIR}/ws2818b.pio)

target_sources(task04-interrupts PRIVATE task04-interrupts.c)

# Add the standard library to the build
target_link_libraries(task04-interrupts
        pico_stdlib
        pico_bootrom
        hardware_pio
        hardware_pwm)

# Add the standard include files to the build
target_include_directories(task04-interrupts PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}
)

# Add any user requested libraries
target_link_libraries(task04-interrupts 
        
        )

pico_add_extra_outputs(task04-interrupts)

