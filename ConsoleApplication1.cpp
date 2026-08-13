// Student Gradebook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>



struct Student {
    std::string name;
    int id;
    double grade;
};

void displayStudents(const std::vector<Student>& students) {
    if (students.empty()) {
        std::cout << "No students in the gradebook.\n";
        return;
    }
    std::cout << "\n--- Student List ---\n";
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << "ID: " << students[i].id << ", Name: " << students[i].name << ", Grade: " << students[i].grade << "\n";
    }
}

double calculateAverageGrade(const std::vector<Student>& students) {
    if (students.empty()) {
        return 0.0;
    }

    double totalGrade = 0.0;
    for (size_t i = 0; i < students.size(); ++i) {
        totalGrade += students[i].grade;
    }
    return totalGrade / students.size();
}

//add student editing system
// add student deletion system
// add sutdent search system
// add student creation error handling system

int main() {
    std::vector<Student> gradebook;
    int choice{};

    while (choice != 4) {
        std::cout << "\n--- Student Gradebook Menu ---\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Display students\n";
        std::cout << "3. Calculate average grade\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            Student newStudent;
            std::cout << "Enter student ID: ";
            std::cin >> newStudent.id;
            std::cout << "Enter student name: ";
            std::cin.ignore(); // Clear the newline character from the input buffer
            std::getline(std::cin, newStudent.name);
            gradebook.push_back(newStudent);
            std::cout << "Enter student grade: ";
            std::cin >> newStudent.grade;

        }
        else if (choice == 2) {
            displayStudents(gradebook);
        }
        else if (choice == 3) {
            double average = calculateAverageGrade(gradebook);
            std::cout << "Average grade: " << average << "\n";

        }
        else if (choice == 4) {
            std::cout << "Exiting gradebook program.\n";

        }
        else {
            std::cout << "Invalid choice. Try again please.\n";
        }
    }


}