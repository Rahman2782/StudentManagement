#pragma once

#include <iostream>
#include <vector>
#include "student.h"

class StudentManager {
    static std::vector<Student> students;
public:
    static void addStudent();
    static void displayMenu();
    //Student* findStudent(int id);
    static void removeStudent(int i);
    static void displayStudent();
    static void addStudentToVector(const Student& s);
};
