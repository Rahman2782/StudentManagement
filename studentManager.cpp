#include "student.h"
#include "studentManager.h"
#include <algorithm>
#include <vector>

std::vector<Student> StudentManager::students;

void StudentManager::addStudent() {
    std::string name;
    int id;
    double g;
    std::string program;

    std::cout << "Enter full student name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Enter studentID: " ;
    std::cin.ignore();
    std::cin >> id;
    std::cout << "Enter GPA: ";
    std::cin >> g;
    std::cout << "Enter Program: ";
    std::cin.ignore();
    std::getline(std::cin, program);
    printf("\n");
    students.emplace_back(id, g, name, program);

    std::cout << "Student added" << std::endl;
}

void StudentManager::removeStudent(int r_id) {
    for(auto i = students.begin(); i != students.end(); ++i) {
        if(i->getID() == r_id) {
            std::cout << i->getName() << " is deleted." << std::endl;
            students.erase(i);
            displayStudent();
            return;
        }
    }
}
//could store index variable to not erase in a loop

void StudentManager::displayMenu() {
    int choice;
    std::cout << "Select a choice:" << std::endl;
    std::cout << "1. Add Student" << std::endl;
    std::cout << "2. Remove Student" << std::endl;
    std::cout << "3. Edit Student" << std::endl;
    std::cout << "4. View all Students" << std::endl;
    std::cout << "0. Quit" << std::endl;
    std::cout << "Enter choice: ";
    std::cin >> choice;
    switch(choice) {
        case 1:
            std::cout << "--------------" << std::endl;
            StudentManager::addStudent();
            break;
        case 2:
            int r_id;
            std::cout << "--------------" << std::endl;
            std::cout << "Enter the ID to be removed: ";
            std::cin >> r_id;
            StudentManager::removeStudent(r_id);
            break;
        case 3:
            //add edit student
        case 4:
            //add display all students
        case 0:
            std::cout << "--------------" << std::endl;
            char q;
            std::cout << "Are you sure (Y/N)?" << std::endl;
            std::cin >> q;
            if(q != 'N' || q != 'Y') {
                std::cout << "NOT VALID - TRY AGAIN: ";
                std:: cin >> q;
                 if(q == 'N') {
                    printf("\n");
                    StudentManager::displayMenu();
                }
                 if (q == 'Y') {
                    exit(0);
                }
            }            
    }
}

void StudentManager::displayStudent() {
    if(students.empty()) {
        std::cout << "No students in the system," << std::endl;
        return;
    }

    std::cout << "Students in the system:" << std::endl;
    for (int q = 0; q < students.size(); q++) {
        std::cout << "Student " << q + 1 << ": " << students[q].getName() 
            << " (ID: " << students[q].getID() << ")" 
            << " (Program: " << students[q].getProgram() << ")" 
            << " (GPA: " << students[q].getGPA() << ")" << std::endl;
    }
}


void StudentManager::addStudentToVector(const Student& s) {
    students.push_back(s);
}