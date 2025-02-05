#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <course.h>
using namespace std;

class Student {
  private:
    int id;
    string name;
    vector<int> enrolledCourses;
    const int MAX_ALLOWED_CREDITS;

  public:
    Student() {
      id = 0;
      name = "Student Name";
      MAX_ALLOWED_CREDITS = 18;
    }

    int getId() const{
      return id;
    }

    string getName() const {
      return name;
    }

    vector<int> getEnrolledCourses() const {
      return enrolledCourses;
    }

    bool takesCourse(Course course) {
      for (int i = 0; i < enrolledCourses.size(); i++) {
        if (enrolledCourses[i] == course.getId()) {
          return true;
        }
      }
      return false;
    }

    bool takeCourse(Course course) {
      int currentCredits = 0;
      for (int i = 0; i < enrolledCourses.size(); i++) {
        currentCredits += enrolledCourses[i].getCredits();
      }
      if (currentCredits + course.getCredits() <= MAX_ALLOWED_CREDITS && takesCourse(course) == false) {
        return true;
      }
      return false;
    }
};


#endif
