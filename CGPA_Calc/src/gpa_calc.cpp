#include <map>
#include <stdexcept>

#include "course.hpp"
using namespace std;

constexpr uint16_t max_grade = 10;
constexpr uint16_t per_cent = 100;

const map<string, uint8_t> GradeToVal{
    {"A", 10}, {"B", 8}, {"C", 6}, {"D", 4}, {"E", 0}};

double cgpa_calculator::calculate_gpa(
    const vector<CourseRecord> &__CourseRecords) {
  uint8_t totalGrades = 0;
  for (const CourseRecord record : __CourseRecords) {
    auto it = GradeToVal.find(record.grade);
    if (it != GradeToVal.end()) {
      totalGrades += static_cast<uint8_t>(it->second);
    } else {
      throw invalid_argument("Invalid Grade Value.");
    }
  }
  return (totalGrades / (double)(__CourseRecords.size() * max_grade)) *
         per_cent;
}