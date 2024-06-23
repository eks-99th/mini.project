#include <gtest/gtest.h>

#include <vector>

#include "course.hpp"

using namespace cgpa_calculator;

TEST(GPA_CALC, ALL_GRADES_100) {
  std::vector<CourseRecord> courses = {
      CourseRecord("Math", "A", 100), CourseRecord("History", "A", 100),
      CourseRecord("Geography", "A", 100), CourseRecord("Arts", "A", 100)};
  double gpa = calculate_gpa(courses);
  ASSERT_EQ(gpa, 100);
}

TEST(GPA_CALC, HALF_TWO_COURSES) {
  std::vector<CourseRecord> courses = {
      CourseRecord("Math", "A", 10),
      CourseRecord("History", "E", 10),
  };
  double gpa = calculate_gpa(courses);
  ASSERT_EQ(gpa, 50);
}

TEST(GPA_CALC, ZERO) {
  std::vector<CourseRecord> courses = {
      CourseRecord("Math", "E", 10),
      CourseRecord("History", "E", 10),
  };
  double gpa = calculate_gpa(courses);
  ASSERT_EQ(gpa, 0);
}