################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/busy.c \
../src/bw_file_rd.c \
../src/bw_mem.c \
../src/bw_pipe.c \
../src/cache.c \
../src/clock.c \
../src/enough.c \
../src/flushdisk.c \
../src/getopt.c \
../src/lat_dram_page.c \
../src/lat_mem_rd.c \
../src/lat_ops.c \
../src/lat_proc.c \
../src/lat_rand.c \
../src/lat_select.c \
../src/lat_syscall.c \
../src/lib_debug.c \
../src/lib_mem.c \
../src/lib_sched.c \
../src/lib_stats.c \
../src/lib_timing.c \
../src/line.c \
../src/loop_o.c \
../src/memsize.c \
../src/mhz.c \
../src/msleep.c \
../src/par_mem.c \
../src/platform.c \
../src/rhttp.c \
../src/timing_o.c \
../src/tlb.c \
../src/vitijumps.c 

LD_SRCS += \
../src/lscript.ld 

OBJS += \
./src/busy.o \
./src/bw_file_rd.o \
./src/bw_mem.o \
./src/bw_pipe.o \
./src/cache.o \
./src/clock.o \
./src/enough.o \
./src/flushdisk.o \
./src/getopt.o \
./src/lat_dram_page.o \
./src/lat_mem_rd.o \
./src/lat_ops.o \
./src/lat_proc.o \
./src/lat_rand.o \
./src/lat_select.o \
./src/lat_syscall.o \
./src/lib_debug.o \
./src/lib_mem.o \
./src/lib_sched.o \
./src/lib_stats.o \
./src/lib_timing.o \
./src/line.o \
./src/loop_o.o \
./src/memsize.o \
./src/mhz.o \
./src/msleep.o \
./src/par_mem.o \
./src/platform.o \
./src/rhttp.o \
./src/timing_o.o \
./src/tlb.o \
./src/vitijumps.o 

C_DEPS += \
./src/busy.d \
./src/bw_file_rd.d \
./src/bw_mem.d \
./src/bw_pipe.d \
./src/cache.d \
./src/clock.d \
./src/enough.d \
./src/flushdisk.d \
./src/getopt.d \
./src/lat_dram_page.d \
./src/lat_mem_rd.d \
./src/lat_ops.d \
./src/lat_proc.d \
./src/lat_rand.d \
./src/lat_select.d \
./src/lat_syscall.d \
./src/lib_debug.d \
./src/lib_mem.d \
./src/lib_sched.d \
./src/lib_stats.d \
./src/lib_timing.d \
./src/line.d \
./src/loop_o.d \
./src/memsize.d \
./src/mhz.d \
./src/msleep.d \
./src/par_mem.d \
./src/platform.d \
./src/rhttp.d \
./src/timing_o.d \
./src/tlb.d \
./src/vitijumps.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo Building file: $<
	@echo Invoking: MicroBlaze gcc compiler
	mb-gcc -Wall -O3 -c -fmessage-length=0 -D __XMK__ -I../../xilkernel_bsp_0/microblaze_0/include -mcpu=v8.20.a -mxl-soft-mul -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo Finished building: $<
	@echo ' '


