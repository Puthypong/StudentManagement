#include "Student.cpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class FileUtil {
public:
    static void writeStudentToFile(const Student& student, std::ofstream& outputFile) {
        outputFile << student.getName() << std::endl;
        outputFile << student.getId() << std::endl;
        outputFile << student.getSex() << std::endl;
        outputFile << student.getAddress() << std::endl;
        outputFile << student.getPhoneNumber() << std::endl;
        outputFile << student.getYear() << std::endl;
    }

    static std::vector<Student> readStudentsFromFile(const std::string& filename) {
        std::vector<Student> students;
        std::ifstream inputFile(filename);

        if (!inputFile) {
            std::cout << "Failed to open the file for reading." << std::endl;
            return students; // Return an empty vector
        }

        std::string name, sex, address, phoneNumber;
        int id, year;

        while (inputFile >> name >> id >> sex >> address >> phoneNumber >> year) {
            // Construct a Student object and add it to the vector
            Student student(name, id, sex, address, phoneNumber, year);
            students.push_back(student);
        }

        inputFile.close();

        return students;
    }
};