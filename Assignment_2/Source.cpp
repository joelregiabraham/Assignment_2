
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#define PRE_RELEASE

struct STUDENT_DATA {
    std::string firstName;
    std::string lastName;
};

int main() {


    std::vector<STUDENT_DATA> students;
    std::ifstream inputFile("../../StudentData.txt");
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


        //
    #ifdef PRE_RELEASE
            std::cout << "Running Pre-Release version\n";
            std::ifstream emailFile("../../StudentData_Emails.txt");
            std::string email;
            for (size_t i = 0; i < students.size() && std::getline(emailFile, email); ++i) {
                std::cout << students[i].firstName << " " << students[i].lastName << ": " << email << std::endl;
            }
    #else
            std::cout << "Running Standard version\n";
    #endif


    inputFile.close();
    return 0;
}
