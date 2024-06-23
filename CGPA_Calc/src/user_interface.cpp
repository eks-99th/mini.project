#include <botan/hash.h>
#include <botan/hex.h>

#include "ftxui/component/component.hpp"       // for Input, Renderer, Vertical
#include "ftxui/component/component_base.hpp"  // for ComponentBase
#include "ftxui/component/screen_interactive.hpp"  // for Component, ScreenInteractive
#include "main.hpp"

using namespace ftxui;

std::string sha256_student_id(std::string &first_name,
                              std::string &second_name);

extern double gGPA;

void render_ui() {
  std::string first_name;
  std::string last_name;
  std::string student_id;
  std::string course_name;
  std::string hours_credits;
  int credit_hours = 0;
  std::string grade = "";

  auto save_button = Button(
      "SAVE", [&] { SaveCourseCallback(course_name, hours_credits, grade); },
      ButtonOption::Animated(Color::GrayLight));

  auto button_a = Button(
      "A", [&] { grade = "A"; }, ButtonOption::Animated(Color::GreenLight));
  auto button_b =
      Button("B", [&] { grade = "B"; }, ButtonOption::Animated(Color::Green));
  auto button_c = Button(
      "C", [&] { grade = "C"; }, ButtonOption::Animated(Color::GreenYellow));
  auto button_d = Button(
      "D", [&] { grade = "D"; }, ButtonOption::Animated(Color::RedLight));
  auto button_e =
      Button("E", [&] { grade = "E"; }, ButtonOption::Animated(Color::Red));

  // The basic input components:
  Component input_first_name = Input(&first_name, "first name");
  Component input_last_name = Input(&last_name, "last name");
  Component course = Input(&course_name, "course");
  Component input_credits = Input(&hours_credits, "credits");

  // The component tree:
  auto component = Container::Vertical(
      {input_first_name, input_last_name, course, button_a, button_b, button_c,
       button_d, button_e, input_credits, save_button});

  // Tweak how the component tree is rendered:
  auto renderer = Renderer(component, [&] {
    student_id = sha256_student_id(first_name, last_name);
    return vbox({
               hbox(text(" First name : "), input_first_name->Render()),
               hbox(text(" Last name  : "), input_last_name->Render()),
               hbox(text(" Student Id  :" + student_id)),
               separator(),
               hbox(text(" Course Name :"), course->Render()),
               hbox(text(" Credits :"), input_credits->Render()),
               separator(),
               vbox({text(" GRADE"), hbox({
                                         button_a->Render(),
                                         button_b->Render(),
                                         button_c->Render(),
                                         button_d->Render(),
                                         button_e->Render(),
                                     })}),
               separator(),
               hbox(save_button->Render()),
               separator(),
               text(" Current GPA :" + std::to_string(gGPA)),
           }) |
           border;
  });

  auto screen = ScreenInteractive::FitComponent();
  screen.Loop(renderer);
}

std::string sha256_student_id(std::string &first_name,
                              std::string &second_name) {
  auto str = first_name + second_name;
  std::vector<uint8_t> buf(2048);
  const auto hash1 = Botan::HashFunction::create_or_throw("SHA-256");
  hash1->update(buf.data(), str.length());
  auto sha = Botan::hex_encode(hash1->final());
  return sha.substr(0, 5);
  ;
}
