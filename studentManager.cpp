#include "student.h"
#include "studentManager.h"
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cctype>

std::vector<Student> StudentManager::students;

void StudentManager::addStudent() {
    std::string name;
    int id;
    double g;
    std::string program;

    std::cout << "Enter full student name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    bool flag = 0;
    do {
        std::cout << "Enter studentID: " ;
        std::cin >> id;
        //bool isDigit = isdigit(id);
        //auto it = std::find_if(students.begin(), students.end(), id);
        //if(it != students.end()) {
        //    std::cout << "The student already exists! try again." << std::endl;
        //} ----------------------std::to_string(id).length() != 9 && !isdigit(id)------------

        if(std::to_string(id).length() != 9 && !isdigit(id)) {
            std::cout << "Student ID should be 9 ints long, try again." << std::endl;
            std::cin.clear();
        }
        //else if(!isdigit(id)) {
        //    std::cout << "Enter a valid number, try again." << std::endl;
        //}
        else if(std::to_string(id).length() == 9 && isdigit(id)) {
            std::cout << "------------PASSED------------" << std::endl;
            flag = 1;
        }
    } while (flag == 0);
    

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
    for(auto i = students.begin(); i != students.end(); i++) {
        if(i->getID() == r_id) {    
            std::cout << i->getName() << " is deleted." << std::endl;
            students.erase(i);
            displayStudentList();
            return;
        }           
    }
    std::cout << "Student not found" << std::endl;
}
//could store index in variable to not erase index directly in a loop

void StudentManager::displayMenu() {
    int loop = 0; 
    do {
        std::cout << "\nSelect a choice:" << std::endl;
        std::cout << "1. Add Student" << std::endl;
        std::cout << "2. Remove Student" << std::endl;
        std::cout << "3. View Student" << std::endl;
        std::cout << "4. View all Students" << std::endl;
        std::cout << "0. Quit" << std::endl;
        std::cout << "Enter choice: ";
        int choice;
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
                int x;
                std::cout << "--------------" << std::endl;
                std::cout << "Enter the student ID: ";
                std::cin >> x;
                StudentManager manager;
                manager.findStudent(x);
                break;
            case 4:
                displayStudentList();
                break;
            case 0:
                std::cout << "--------------" << std::endl;
                loop = 1;
                exit(1);
                //char q;
                //std::cout << "Are you sure (Y/N)?" << std::endl;
                //std::cin >> q;
                /*
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
                */ //logic needs to be fixed for quitting (or removed entirely)
                           
        } 
    } while (loop == 0);
    
}

void StudentManager::displayStudentList() {
    if(students.empty()) {
        std::cout << "No students in the system." << std::endl;
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

void StudentManager::displayStudent(const int x) {
    for(auto i = 0; i < students.size(); i++) {
        if(students[i].getID() == x) {
            std::cout << "StudentID: " << students[i].getID()
                      << " Name: " << students[i].getName() << std::endl;
                      return;
        }
    }
    std::cout << "---Student not found---" << std::endl;
}

Student* StudentManager::findStudent(int id) {
    for(auto i = 0; i < students.size(); i++) {
        if(students[i].getID() == id) {
            /*
                std::cout << "Name: " << students[i].getName()
                << " (ID: " << students[i].getID() << ")" 
                << " (Program: " << students[i].getProgram() << ")" 
                << " (GPA: " << students[i].getGPA() << ")" << std::endl;
            */
            StudentHandler manager(students[i]);
            manager.displayStudent();
            StudentHandler::displayStudentMenu(manager);

            return &students[i]; //returns the student object found with ID
        }
    }
    std::cout << "---Student not found---" << std::endl;
    return nullptr;
}

void StudentManager::addStudentToVector(const Student& s) {
    students.push_back(s);
}

void StudentHandler::displayStudentMenu(StudentHandler& handler) {
    int loop = 0; 
    do {
        std::cout << "\nSelect a choice:" << std::endl;
        std::cout << "1. Remove Student" << std::endl;
        std::cout << "0. Back" << std::endl;
        std::cout << "Enter choice: ";
        int choice;
        std::cin >> choice;
        switch(choice) {
            case 1:
                int r_id;
                std::cout << "--------------" << std::endl;
                handler.removeStudent();
                break;
            case 0:
                StudentManager::displayMenu();
                break;
        } 
    } while (loop == 0);
    
}
