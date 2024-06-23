#ifndef COURSE_H
#define COURSE_H

using namespace std;
#include <string>
#include <vector>

namespace cgpa_calculator {
class CourseRecord {
 private:
  string courseName;
  string grade;
  uint16_t credit_hours;

 public:
  CourseRecord(const string &_courseName, const string _grade,
               const uint16_t _credit_hours);
  friend double calculate_gpa(const vector<CourseRecord> &__CourseRecords);
};

double calculate_gpa(const vector<CourseRecord> &__CourseRecords);
}  // namespace cgpa_calculator
#endif