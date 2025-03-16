#pragma once

#include <iostream>
#include <vector>
#include "student.h"

class StudentManager {
    static std::vector<Student> students;
public:
    static void addStudent();
    static void displayMenu();
    Student* findStudent(int id);
    static void removeStudent(int i);
    static void displayStudentList();
    static void displayStudent(const int i); //should be in student.h?
    static void addStudentToVector(const Student& s);
};


//helper class
class StudentHandler {
private:
    Student& studentReference;
    bool isRemoved = false;
public:
    StudentHandler(Student& student) : studentReference(student) {};
    void removeStudent() {
        if(isRemoved) {
            std::cout << "ERROR: Student already removed!" << std::endl;
        }
        else {
            std::cout << "Removing student: " << studentReference.getName() << "\n" << std::endl;
            StudentManager::removeStudent(studentReference.getID());
            isRemoved = true;
        }     
    }

    void displayStudent() {
        std::cout << "Name: " << studentReference.getName() << std::endl;
        std::cout << "Program: " << studentReference.getProgram() << std::endl;
        std::cout << "GPA: " << studentReference.getGPA() << std::endl;
    }

    static void displayStudentMenu(StudentHandler& manager);
};
