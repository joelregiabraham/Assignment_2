
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct STUDENT_DATA {
    std::string firstName;
    std::string lastName;
};

int main() {
    std::vector<STUDENT_DATA> students;
    std::ifstream inputFile("StudentData.txt");
    std::string line;

    while (std::getline(inputFile, line)) {
        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            STUDENT_DATA student;
            student.firstName = line.substr(0, commaPos);
            student.lastName = line.substr(commaPos + 1);
            students.push_back(student);
        }
    }
        // DEBUG mode: Print student data to the console
    #ifdef _DEBUG
        std::cout << "Running in DEBUG mode.\n";
        for (const auto& student : students) {
            std::cout << student.firstName << " " << student.lastName << std::endl;
        }
    #endif




    inputFile.close();
    return 0;
}
