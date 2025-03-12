#include <iostream>
#include <string>
#include <cstring>
#include "student.h"
#include "studentManager.h"

int Student::numOfStudents{0};

//constructor
Student::Student(int id, double gpa, const std::string name, std::string program)
    : m_studentID(id), m_gpa(gpa), m_name(name), m_program(program) { //was missing name 
        std::cout << "Account for " << name << " created." << std::endl;
        numOfStudents++;
    }

Student &Student::operator=(const Student& src) {
    std::cout << "COPY ASSIGNMENT" << std::endl;
    if(this != &src) { 
        m_name = src.m_name;
        m_gpa = src.m_gpa;
        m_program = src.m_program;
        m_studentID = src.m_studentID; 
    }
        return *this;
}

//copy constructor
Student::Student(const Student &src) 
    : m_gpa(src.m_gpa), m_name(src.m_name), m_studentID(src.m_studentID), m_program(src.m_program) {
    std::cout << "COPY ENVOKED" << std::endl;
    numOfStudents++;
}

//move constructor 
Student::Student(Student &&src) noexcept
    : m_gpa(std::move(src.m_gpa)), m_studentID(std::move(src.m_studentID)), 
      m_name(std::move(src.m_name)), m_program(std::move(src.m_program)) {
    std::cout << "MOVE ENVOKED" << std::endl;
}

//move assignment operator
Student& Student::operator=(Student &&src) {
    if(this == &src) {
        return *this;
    }
    //src.m_gpa = 0.0;
    //src.m_name = "";
    //src.m_studentID = 0;
    //src.m_program = "";
    m_gpa = std::move(src.m_gpa);
    m_studentID = std::move(src.m_studentID);
    m_name = std::move(src.m_name);
    m_program = std::move(src.m_program);

    return *this;
}

//destructor
Student::~Student() {}


