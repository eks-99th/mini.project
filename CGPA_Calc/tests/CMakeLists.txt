find_library(GTEST_LIB gtest HINTS /usr/local/lib)
find_library(GTEST_MAIN_LIB gtest_main HINTS /usr/local/lib)


add_executable(COURSE_TESTS course_tests.cpp)
target_include_directories(COURSE_TESTS PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(COURSE_TESTS ${GTEST_LIB} ${GTEST_MAIN_LIB} pthread course)
add_test(NAME ${PROJECT_NAME}_COURSE_TESTS COMMAND COURSE_TESTS)


