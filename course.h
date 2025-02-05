#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <student.h>

using namespace std;

class Course {
  private:
    int id;
    string name;
    int credits;
    vector<int> students;

  public:
    Course() {
      id = 0;
      name = "Course Name";
      credits = 0;
    }

    int getId() const {
      return id;
    }

    string getName() const {
      return name;
    }

    int getCredits() const {
      return credits;
    }


};




#endif
