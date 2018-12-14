set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)

cmake_minimum_required(VERSION 3.7)

# Setup the ARM cross compilation toolchain.
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(AS arm-none-eabi-as)
set(AR arm-none-eabi-ar)
set(OBJCOPY arm-none-eabi-objcopy)
set(OBJDUMP arm-none-eabi-objdump)
set(SIZE arm-none-eabi-size)

# Points to the linker script for our specific MCU.
set(LINKER_SCRIPT ${CMAKE_SOURCE_DIR}/STM32F427VITx_FLASH.ld)

# Enable hardware floating point support.
set(FPU_FLAGS "-mfloat-abi=hard -mfpu=fpv4-sp-d16")
add_definitions(-DARM_MATH_CM4 -DARM_MATH_MATRIX_CHECK -DARM_MATH_ROUNDING)

# The common flags across C and C++ files.
set(COMMON_FLAGS "-mcpu=cortex-m4 ${FPU_FLAGS} -mthumb -mthumb-interwork -ffunction-sections -fdata-sections -fno-common -fmessage-length=0 -specs=nosys.specs -specs=nano.specs")

# Set the C and C++ flags.
set(CMAKE_CXX_FLAGS_INIT "${COMMON_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS_INIT "${COMMON_FLAGS} -std=gnu99")

# Set the linker flags to allow dead-code removal and to run our MCU script.
set(CMAKE_EXE_LINKER_FLAGS_INIT "-Wl,-gc-sections -T ${LINKER_SCRIPT}")

# Setting up the CMake project.
PROJECT(IREC19-FC C ASM)
set(CMAKE_CXX_STANDARD 11)

# Definitions required to use the STM32 HAL.
add_definitions(-D__weak=__attribute__\(\(weak\)\) -D__packed=__attribute__\(\(__packed__\)\) -DUSE_HAL_DRIVER -DSTM32F427xx )

# Set the SOURCES variable to the HAL sources, our sources, and the startup assembly.
file(GLOB_RECURSE SOURCES
        startup_stm32f427xx.s
        FlightComputer.c
        System/*.c
        States/*.c
        Drivers/STM32F4xx_HAL_Driver/Src/*.c)

# Include all of the header directories.
include_directories(
        .
        System
        States
        Drivers/STM32F4xx_HAL_Driver/Inc
        Drivers/STM32F4xx_HAL_Driver/Inc/Legacy
        Drivers/CMSIS/Device/ST/STM32F4xx/Include
        Drivers/CMSIS/Include)

# Create our main .elf file.
add_executable(${PROJECT_NAME}.elf ${SOURCES} ${LINKER_SCRIPT})

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Map=${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map")

set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)

# Generate .hex and .bin files from the .elf file.
add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -Oihex $<TARGET_FILE:${PROJECT_NAME}.elf> ${HEX_FILE}
        COMMAND ${CMAKE_OBJCOPY} -Obinary $<TARGET_FILE:${PROJECT_NAME}.elf> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE}
Building ${BIN_FILE}")

# CMake target to upload the compiled ELF to the target MCU.
#add_custom_target(UPLOAD
#        arm-none-eabi-gdb -iex "target remote tcp:127.0.0.1:3333"
#        -iex "monitor program $<TARGET_FILE:${PROJECT_NAME}.elf>"
#        -iex "monitor reset init"
#        -iex "disconnect" -iex "quit")