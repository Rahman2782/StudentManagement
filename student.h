#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

    class Student {
        static int numOfStudents;
        int m_studentID;
        double m_gpa;
        std::string m_name;
        std::string m_program;
    public:
        Student(int id, double gpa, const std::string name, std::string program);
        ~Student();
        Student(const Student &src); //copy constructor
        Student &operator=(const Student& src); //copy assignment operator
        Student(Student &&src) noexcept; //move constructor
        Student &operator=(Student &&src);
        //void display();

        //Getters
        std::string getName() const { return m_name; }
        int getID() const { return m_studentID; }
        float getGPA() const { return m_gpa; }
        std::string getProgram() const { return m_program; }
        static int getNumOfStudents() { return numOfStudents;};

        //Setters
        void setName(std::string n) { this->m_name; }
        void setID(int i) { this->m_studentID; }
        void setGPA(float g) { this->m_gpa; }
        void setMajor(std::string m) { this->m_program; }

        //using "this" makes it so m_studentID can just be studentID
    };



    
    

