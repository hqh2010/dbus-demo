# 开启GTest开关
enable_testing()

find_package(GTest REQUIRED)

set(LINK_LIBS
    GTest::GTest
    GTest::Main
    stdc++
)
aux_source_directory(../src/utils UTILS_SRC)
# 相当于Makefile的　-I
include_directories(../src/utils  SRC_INCLUDE)
set(GTEST_SOURCES
        ${UTILS_SRC}
        Function_Test.cpp
        )
# CMake　相对路径
# file(GLOB GTEST_SOURCES ./*.cpp)

add_executable(func_test ${GTEST_SOURCES})

target_link_libraries(func_test PRIVATE ${LINK_LIBS})

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#add_test(func_test func_test)
add_test(NAME func_test COMMAND func_test)