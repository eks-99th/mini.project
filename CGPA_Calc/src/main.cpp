#include "main.hpp"

#include <vector>

#include "course.hpp"
#include "user_interface.hpp"

using namespace cgpa_calculator;
vector<CourseRecord> all_courses = {};
double gGPA = 0;

int main() { render_ui(); }

void SaveCourseCallback(std::string course_name, std::string hours_credits,
                        std::string grade) {
  uint8_t hours = std::stoi(hours_credits);
  CourseRecord new_course = CourseRecord(course_name, grade, hours);
  all_courses.push_back(new_course);
  gGPA = calculate_gpa(all_courses);
  // Create Course object
  // Add to course array
  // Calculate gpa
  // print GPA

  // Implement the logic to save the course registration here (assuming this is
  // the desired functionality)
}
