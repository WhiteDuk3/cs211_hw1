#include <iostream>
using namespace std;
#include "LMS.h"


int main() {
  string LMSname;
  getline(cin, LMSname);
  LMS myLMS(LMSname);
  int number_of_students;
  cin >> number_of_students;

  for (int i = 0; i < number_of_students; i++) {
    int id;
    string name;
    cin >> id >> name;
    Student student1(id, name);
    myLMS.addStudent(student1);
  }


  return 0;
}