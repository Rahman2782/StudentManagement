#include "student.h"
#include "studentManager.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;


int main() {
    std::cout << "Student Management System" << std::endl;
    std::cout << "-------------------------" << std::endl;

    Student adam{1234556, 3.3, "Adam Rivera", "Biology"};
    Student lucy{4356363, 3.5, "Lucy McLean", "Dweller"};
    Student john{3638887, 2.3, "John Walker", "Soldier"};
    Student ikora{3467900, 3.1, "Ikora Rey", "Warlock"};
    Student arthur{4454667, 1.7, "Arthur Morgan", "Wrangler"};
    Student cloud{3453244, 4.0, "Cloud Strife", "Mercenary"};
    Student mario{1284323, 3.0, "Mario Bro", "Plumber"};

    StudentManager::addStudentToVector(adam);
    StudentManager::addStudentToVector(lucy);
    StudentManager::addStudentToVector(john);
    StudentManager::addStudentToVector(ikora);
    StudentManager::addStudentToVector(arthur);
    StudentManager::addStudentToVector(cloud);
    StudentManager::addStudentToVector(mario);

    int quit = 0;
    StudentManager::displayMenu();

    //StudentManager manager;
    //manager.addStudent();
    
    
    

    return 0;
}
