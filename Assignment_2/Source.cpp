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

    // Check if file is opened
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

    // Read data from file
    std::cout << "Reading data from file:" << std::endl;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;  // Print the line to check

        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            STUDENT_DATA student;
            student.firstName = line.substr(0, commaPos);
            student.lastName = line.substr(commaPos + 1);
            students.push_back(student);
        }
    }

    // DEBUG: Print student data if compiled in Debug mode
#ifdef _DEBUG
    std::cout << "Student Data in Debug Mode:" << std::endl;
    for (const auto& student : students) {
        std::cout << student.firstName << " " << student.lastName << std::endl;
    }
#endif

    // PRE-RELEASE: Handle email data
#ifdef PRE_RELEASE
    std::cout << "Running in Pre-Release mode" << std::endl;
    std::ifstream emailFile("StudentData_Emails.txt");
    std::string email;
    for (size_t i = 0; i < students.size() && std::getline(emailFile, email); ++i) {
        std::cout << students[i].firstName << " " << students[i].lastName << ": " << email << std::endl;
    }
#endif

    inputFile.close();
    return 0;
}