#include <gtest/gtest.h>

#include <course.hpp>
#include <iostream>
#include <stdexcept>
#include <string>
#include <tuple>

using namespace cgpa_calculator;

TEST(DATA_ENTRY, COURSE_ELEMENT_EXISTS) {
  string name = "CS101";
  string grade = "A";
  uint16_t credit = 3;
  CourseRecord *course = new CourseRecord(name, grade, credit);
  ASSERT_NE(course, nullptr);
}

class CourseRecordTest
    : public ::testing::TestWithParam<tuple<string, string, uint16_t>> {
 protected:
};

INSTANTIATE_TEST_SUITE_P(CourseRecordTestCases, CourseRecordTest,
                         ::testing::Values(make_tuple("Math", "A", 3),
                                           make_tuple("History", "A", 3),
                                           make_tuple("Science", "A", 3)));

TEST_P(CourseRecordTest, ValidateCourseRecord) {
  string name = get<0>(GetParam());
  string grade = get<1>(GetParam());
  uint16_t credit = get<2>(GetParam());
  EXPECT_NO_THROW(CourseRecord(name, grade, credit));
}

TEST(DATA_ENTRY, COURSE_NAME_CANNOT_BE_EMPTY) {
  string name = "";
  string grade = "A";
  uint16_t credit = 3;
  EXPECT_THROW({ CourseRecord course(name, grade, credit); }, invalid_argument);
}

TEST(DATA_ENTRY, COURSE_NAME_CANNOT_LONGER_THAN_180_CHARS) {
  string name = string(181, 'x');
  string grade = "A";
  uint16_t credit = 3;
  EXPECT_THROW({ CourseRecord course(name, grade, credit); }, invalid_argument);
}

TEST(DATA_ENTRY, COURSE_GRADE_CANNOT_BE_EMPTY) {
  string name = "My Course";
  string grade = "";
  uint16_t credit = 3;
  EXPECT_THROW({ CourseRecord course(name, grade, credit); }, invalid_argument);
}

TEST(DATA_ENTRY, COURSE_GRADE_MUST_BE_ABCDE) {
  string name = "My Course";
  string grade = "X";
  uint16_t credit = 3;
  EXPECT_THROW({ CourseRecord course(name, grade, credit); }, invalid_argument);
}

TEST(DATA_ENTRY, COURSE_CREDIT_HOURS_MUST_BE_GREATER_THAN_1) {
  string name = "My Course";
  string grade = "A";
  uint16_t credit_hours = 0;
  EXPECT_THROW(
      { CourseRecord course(name, grade, credit_hours); }, invalid_argument);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}