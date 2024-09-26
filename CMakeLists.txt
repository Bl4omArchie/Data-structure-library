cmake_minimum_required(VERSION 3.10)

# Project name
project(Data Structure Library)

# Set the build directories
set(SRCDIR src)
set(TESTDIR tests)
set(INCDIR includes)
set(BUILDDIR ${CMAKE_BINARY_DIR}/build)
set(TARGET file)

include_directories(${INCDIR})


file(GLOB_RECURSE SRCS
    "${SRCDIR}/associative_array/*.c"
    "${SRCDIR}/linked_list/*.c"
    "${SRCDIR}/util/*.c"
    "${TESTDIR}/*.c"
)
file(GLOB ASMS "${SRCDIR}/util/*.asm")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILDDIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILDDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILDDIR})

add_executable(${TARGET} ${SRCS} ${ASMS} main.c)
target_compile_options(${TARGET} PRIVATE -pg)

# Custom command to handle assembly files
foreach(ASM_FILE ${ASMS})
    get_filename_component(ASM_FILE_NAME ${ASM_FILE} NAME_WE)
    add_custom_command(
        OUTPUT ${BUILDDIR}/util/${ASM_FILE_NAME}.o
        COMMAND ${ASM} -f elf64 -o ${BUILDDIR}/util/${ASM_FILE_NAME}.o ${ASM_FILE}
        DEPENDS ${ASM_FILE}
    )
    list(APPEND ASM_OBJECTS ${BUILDDIR}/util/${ASM_FILE_NAME}.o)
endforeach()

# Link the ASM object files with the C objects
target_link_libraries(${TARGET} PRIVATE ${ASM_OBJECTS})

add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${BUILDDIR}
    COMMAND ${CMAKE_COMMAND} -E remove ${TARGET}
)
