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

    for (const auto& student : students) {
        std::cout << "ID: " << student.id
            << ", Name: " << student.name
            << ", Grade: " << student.grade << "\n";
    }
}

double calculateAverageGrade(const std::vector<Student>& students) {
    if (students.empty()) {
        return 0.0;
    }

    double totalGrade = 0.0;

    for (const auto& student : students) {
        totalGrade += student.grade;
    }

    return totalGrade / students.size();
}

int main() {
    std::vector<Student> gradebook;
    int choice = 0;

    while (choice != 7) {
        std::cout << "\n--- Student Gradebook Menu ---\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Edit student\n";
        std::cout << "3. Delete student\n";
        std::cout << "4. Display students\n";
        std::cout << "5. Calculate average grade\n";
        std::cout << "6. Search student\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        if (choice == 1) {
            Student newStudent;

            std::cout << "Enter student ID: ";
            std::cin >> newStudent.id;

            bool duplicateId = false;

            for (const auto& student : gradebook) {
                if (student.id == newStudent.id) {
                    duplicateId = true;
                    break;
                }
            }

            if (duplicateId) {
                std::cout << "Error: A student with this ID already exists.\n";
                continue;
            }

            std::cout << "Enter student name: ";
            std::cin.ignore();
            std::getline(std::cin, newStudent.name);

            do {
                std::cout << "Enter student grade (0-100): ";
                std::cin >> newStudent.grade;

                if (newStudent.grade < 0 || newStudent.grade > 100) {
                    std::cout << "Invalid grade. Please enter a grade between 0 and 100.\n";
                }

            } while (newStudent.grade < 0 || newStudent.grade > 100);

            gradebook.push_back(newStudent);

            std::cout << "Student added successfully.\n";
        }

        else if (choice == 2) {
            int editId;
            std::cout << "Enter the ID of the student you would like to edit: ";
            std::cin >> editId;

            bool found = false;

            for (size_t i = 0; i < gradebook.size(); i++) {
                if (gradebook[i].id == editId) {
                    found = true;

                    std::cout << "Editing student: "
                        << gradebook[i].name << "\n";

                    std::cout << "Enter new name (or press Enter to keep current): ";

                    std::cin.ignore();
                    std::string newName;
                    std::getline(std::cin, newName);

                    if (!newName.empty()) {
                        gradebook[i].name = newName;
                    }

                    std::cout << "Enter new grade (-1 to keep current): ";

                    double newGrade;
                    std::cin >> newGrade;

                    if (newGrade != -1) {
                        if (newGrade >= 0 && newGrade <= 100) {
                            gradebook[i].grade = newGrade;
                        }
                        else {
                            std::cout << "Invalid grade. Keeping current grade.\n";
                        }
                    }

                    std::cout << "Student updated successfully.\n";
                    break;
                }
            }

            if (!found) {
                std::cout << "Student with ID "
                    << editId
                    << " not found.\n";
            }
        }

        else if (choice == 3) {
            int deleteId;

            std::cout << "Enter the ID of the student you would like to delete: ";
            std::cin >> deleteId;

            bool found = false;

            for (size_t i = 0; i < gradebook.size(); i++) {
                if (gradebook[i].id == deleteId) {
                    found = true;

                    gradebook.erase(gradebook.begin() + i);

                    std::cout << "Student deleted successfully.\n";
                    break;
                }
            }

            if (!found) {
                std::cout << "Student with ID "
                    << deleteId
                    << " not found.\n";
            }
        }

        else if (choice == 4) {
            displayStudents(gradebook);
        }

        else if (choice == 5) {
            double average = calculateAverageGrade(gradebook);

            std::cout << "Average grade: "
                << average
                << "\n";
        }

        else if (choice == 6) {
            char searchChoice;

            std::cout << "Would you like to search by Name or ID? (n/i): ";
            std::cin >> searchChoice;

            if (searchChoice == 'i') {
                int searchId;

                std::cout << "Enter student ID: ";
                std::cin >> searchId;

                bool found = false;

                for (const auto& student : gradebook) {
                    if (student.id == searchId) {
                        found = true;

                        std::cout << "Student found:\n";
                        std::cout << "ID: " << student.id
                            << ", Name: " << student.name
                            << ", Grade: " << student.grade << "\n";

                        break;
                    }
                }

                if (!found) {
                    std::cout << "Student with ID "
                        << searchId
                        << " not found.\n";
                }
            }

            else if (searchChoice == 'n') {
                std::string searchName;

                std::cout << "Enter student name: ";

                std::cin.ignore();
                std::getline(std::cin, searchName);

                bool found = false;

                for (const auto& student : gradebook) {
                    if (student.name == searchName) {
                        found = true;

                        std::cout << "Student found:\n";
                        std::cout << "ID: " << student.id
                            << ", Name: " << student.name
                            << ", Grade: " << student.grade << "\n";

                        break;
                    }
                }

                if (!found) {
                    std::cout << "Student with name \""
                        << searchName
                        << "\" not found.\n";
                }
            }

            else {
                std::cout << "Invalid search option.\n";
            }
        }

        else if (choice == 7) {
            std::cout << "Exiting gradebook program.\n";
        }

        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}