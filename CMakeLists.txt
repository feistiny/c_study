cmake_minimum_required(VERSION 3.17)
project(c_study C)

set(CMAKE_C_STANDARD 11)

# 设置gcc的编译flags
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DDEBUG")

# 设置二进制文件的生成路径
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#
## 添加可执行文件
add_executable(day01.hello-world day01.hello-world/main.c)
add_executable(day02.data-type day02.data-type/main.c)
add_executable(day02.data-type.convert day02.data-type/convert.c)

add_executable(day03.vars day03.vars/main.c)
add_executable(day03.vars.extern day03.vars/extern/main.c day03.vars/extern/addtwonum.c)
add_executable(day03.vars.string day03.vars/string.c)
add_executable(day03.vars.case day03.vars/case.c)

add_executable(day04.pointer day04.pointer/main.c)
add_executable(day04.pointer.struct_pointer day04.pointer/struct_pointer.c)
add_executable(day04.pointer.pointer_pointer day04.pointer/pointer_pointer.c)
add_executable(day04.pointer.local_pointer day04.pointer/local_pointer.c)

add_executable(day05.struct day05.struct/main.c)
add_executable(day05.struct.union_struct_order day05.struct/union_struct_order.c)
add_executable(day06.union day06.union/main.c)
add_executable(day07.input-ouput day07.input-ouput/main.c)
add_executable(day08.file day08.file/main.c day08.file/mkdir.c day08.file/test.c)
add_executable(day09.macro day09.macro/main.c)
target_compile_options(day09.macro PUBLIC
        -DDEBUG
        -DMACRO_STR="bbb"
        )
add_executable(day10.error day10.error/main.c)
add_executable(day11.va_list day11.va_list/main.c)
add_executable(day12.malloc day12.malloc/main.c)
add_executable(day13.argv day13.argv/main.c)

add_executable(hello_world examples/hello_world.c)

# plugin 自动生成的 add_executable

add_executable(alg.cslink.cycle_check algs/alg.cslink.cycle_check.c)
add_executable(alg.cslink.combine algs/alg.cslink.combine.c)
add_executable(alg.cslink.reverse algs/alg.cslink.reverse.c)
add_executable(eg.test examples/eg.test.c)
add_executable(alg.cslink.test algs/alg.cslink.test.c)
add_executable(alg.cslink.del_-n algs/alg.cslink.delete.c)
add_executable(alg.cslink.mid_node algs/alg.cslink.mid_node.c)
add_executable(alg.cslink.palindrome algs/alg.cslink.palindrome.c)