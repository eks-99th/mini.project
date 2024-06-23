#include "course.hpp"

#include <algorithm>
#include <array>
#include <stdexcept>

using namespace std;
using namespace cgpa_calculator;
constexpr uint16_t MAX_COURSE_NAME_SZ = 180;
constexpr uint16_t MIN_HOURS = 1;
const std::array<std::string, 5> validGrades = {"A", "B", "C", "D", "E"};

namespace {
void validate_values(const std::string &_grade);
void validate_course_name(const string &_courseName) {
  if (_courseName.empty() == true) {
    throw std::invalid_argument("Course name cannot be empty");
    std::exit(EXIT_FAILURE);
  } else if (_courseName.length() > MAX_COURSE_NAME_SZ) {
    throw std::invalid_argument("Course name cannot be empty");
    std::exit(EXIT_FAILURE);
  }
}

void validade_grade(const std::string &_grade) {
  if (_grade.empty() == true) {
    throw std::invalid_argument("Grade cannot be empty");
    std::exit(EXIT_FAILURE);
  }

  validate_values(_grade);
}

void validate_values(const std::string &_grade) {
  if (find(validGrades.begin(), validGrades.end(), _grade) ==
      validGrades.end()) {
    string allGrades;
    for (const string &grade : validGrades) {
      allGrades += grade;
    }
    throw invalid_argument("Invalid Grade Value. Valid values are " +
                           allGrades);
  }
}
}  // namespace

CourseRecord::CourseRecord(const string &_courseName, const string _grade,
                           const uint16_t _credit_hours) {
  validate_course_name(_courseName);
  validade_grade(_grade);
  if (_credit_hours < MIN_HOURS)
    throw std::invalid_argument(
        "Invalid Credit Hours Value. Credit hours must be greater than " +
        MIN_HOURS);
  this->courseName = _courseName;
  this->grade = _grade;
  this->credit_hours = _credit_hours;
}
