#ifndef LMS_H
#define LMS_H
#include <iostream>
#include <vector>
using namespace std;
#include "Student.h"
#include "course.h"

class LMS {
  private:
    string name;
    vector<Student> students;
    vector<Course> courses;

  public:
    LMS(string name) {
      this->name = name;
    }

    void addStudent(Student student) {
      students.push_back(student);
    }

    void addCourse(Course course) {
      courses.push_back(course);
    }

    void addStudentToCourse(Student student, Course course) {
      if (!student.takesCourse(course) && !course.hasStudent(student)) {
        course.addStudent(student);
        student.takeCourse(course);
        bool isCourse = false;
        for (int i = 0; i < courses.size(); i++) {
          if (courses[i].getId() == course.getId()) {
            isCourse = true;
            break;
          }
        }
        if (!isCourse) {
          courses.push_back(course);
        }

        bool isStudent = false;
        for (int i = 0; i < students.size(); i++) {
          if (students[i].getId() == student.getId()) {
            isStudent = true;
            break;
          }
        }
        if (!isStudent) {
          students.push_back(student);
        }
      }
    }

    void printDetails(){
      cout << "LMS Name: " << name << endl;
      cout << "LMS Students: ";
      for (int i = 0; i < students.size(); i++) {
        cout << students[i].getName() << endl;
      }
      cout << "LMS Courses: ";
      for (int i = 0; i < courses.size(); i++) {
        cout << courses[i].getName() << endl;
      }
    }
};


#endif