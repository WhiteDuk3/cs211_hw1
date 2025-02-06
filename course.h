#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <vector>

#include "Student.h"

using namespace std;
class Course {
  private:
    int id;
    string name;
    int credits;
    vector<Student> students;

  public:
    Course(int id, string name, int credits) {
      this->id = id;
      this->name = name;
      this->credits = credits;
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

    bool hasStudent(Student student) {
      for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == student.getId()) {
          return true;
        }
      }
      return false;
    }

    bool addStudent(Student student) {
      if (!hasStudent(student)) {
        students.push_back(student);
        return true;
      }
      return false;
    }

    void dropStudent(Student student) {
      for (int i = 0; i < students.size(); i++) {
        if (students[i] == student) {
          students.erase(students.begin() + i);
        }
      }
    }

    void printDetails(){
      cout << "Course ID: " << id << endl;
      cout << "Course Name: " << name << endl;
      cout << "Course Credits: " << credits << endl;
      for (int i = 0; i < students.size(); i++) {
        cout << "List of Student IDs: " << students[i].getId() << endl;
      }
    }
};




#endif

