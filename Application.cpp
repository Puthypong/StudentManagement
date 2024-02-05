#include "Student.cpp"
#include "FileUtil.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

#include "DataValidation.cpp"

class Application
{
public:
    void run()
    {
        int choice;

        do
        {
            cout << "Choose an option:" << endl;
            cout << "1. Add Student" << endl;
            cout << "2. Display All Students" << endl;
            cout << "3. Update Student by ID" << endl;
            cout << "4. Delete Student by ID" << endl;
            cout << "5. Search Students" << endl;
            cout << "0. Quit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                addStudent();
                break;
            case 2:
                displayAllStudent();
                break;
            case 3:
                int idToUpdate;
                cout << "Enter the ID of the student to update: ";
                cin >> idToUpdate;
                updateStudentById(idToUpdate);
                break;
            case 4:
                int idToDelete;
                cout << "Enter the ID of the student to delete: ";
                cin >> idToDelete;
                deleteStudentById(idToDelete);
                break;
            case 5:
                searchStudents();
                break;
            case 0:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        } while (choice != 0);
    }

private:
    void addStudent()
    {
        string name, sex, address, phone_number;
        int year;

        
        DataValidation dataValidation;


        bool validInput = false;

        // Get user input for student details
        cout << "Enter student name: ";
        name = dataValidation.get_st();

        // Determine the next available ID
        vector<Student> students = FileUtil::readStudentsFromFile("student.txt");
        int nextId = 1;
        if (!students.empty())
        {
            nextId = students.back().getId() + 1;
        }
        int id = nextId;

        //Input The Gender With Validation
        cout << "Enter student sex (male/female or Male/Female): ";
        while (!validInput) {
            
            cin >> sex;

            // Convert input to lowercase
            for (char &c : sex) {
                c = tolower(c);
            }

            // Validate the input
            if (sex == "male" || sex == "female" || sex == "Male" || sex =="Female") {
                validInput = true;
            } else {
                cout << "Invalid input. Please enter 'male' or 'female'." << endl;
            }
        }
   
        cout << "Enter student address: ";
        cin >> address;


        cout << "Enter the year (between 1 and 4): ";
        year = dataValidation.getYear();
        
        
        cout << "Enter student phone number: ";
        phone_number = dataValidation.getPhoneNumber();

        // Create a Student object using user input
        Student student = Student(name, id, sex, address, phone_number, year);

        // Open the file for appending
        ofstream outputFile("student.txt", ios::app);
        if (!outputFile)
        {
            cout << "Failed to open the file for writing." << endl;
            return;
        }

        // Write student data to file
        FileUtil::writeStudentToFile(student, outputFile);
        outputFile.close();

        cout << "Data saved to file." << endl;
    }

    void displayAllStudent()
    {
        vector<Student> students = FileUtil::readStudentsFromFile("student.txt");

        for (int i = 0; i < students.size(); i++)
        {
            students[i].display();
        }
    }

    void updateStudentById(int id)
    {

        DataValidation dataValidation;
        vector<Student> students = FileUtil::readStudentsFromFile("student.txt");
        bool found = false;

        // Iterate through the vector to find the student with the given ID
        for (auto it = students.begin(); it != students.end(); ++it)
        {
            if (it->getId() == id)
            {
                found = true;
                // Display student's information
                it->display();
                // Prompt the user to confirm the update
                char confirm;
                cout << "Do you want to update this student's information? (y/n): ";
                cin >> confirm;

                if (confirm == 'y' || confirm == 'Y') {
                    // Prompt the user to choose which information to update
                    int choice;
                    cout << "Choose which information to update:" << endl;
                    cout << "1. Name" << endl;
                    cout << "2. Sex" << endl;
                    cout << "3. Address" << endl;
                    cout << "4. Phone Number" << endl;
                    cout << "5. Year" << endl;
                    cout << "0. Cancel" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    // Variables to store new values
                    string newName, newSex, newAddress, newPhoneNumber;
                    int newYear;

                    // Update the chosen information
                    switch (choice)
                    {
                    case 1:
                        cout << "Enter new name: ";
                        newName = dataValidation.get_st();
                        it->setName(newName);
                        break;
                    case 2:
                        cout << "Enter new sex: ";
                        cin >> newSex;
                        it->setSex(newSex);
                        break;
                    case 3:
                        cout << "Enter new address: ";
                        cin >> newAddress;
                        it->setAddress(newAddress);
                        break;
                    case 4:
                        cout << "Enter new phone number: ";
                        newPhoneNumber = dataValidation.getPhoneNumber();
                        it->setPhoneNumber(newPhoneNumber);
                        break;
                    case 5:
                        cout << "Enter new year: ";
                        newYear = dataValidation.getYear();
                        it->setYear(newYear);
                        break;
                    case 0:
                        cout << "Update canceled." << endl;
                        break;
                    default:
                        cout << "Invalid choice. Update canceled." << endl;
                        break;
                    }
                    // Rewrite all students to the file
                    ofstream outputFile("student.txt");
                    for (const auto &student : students)
                    {
                        FileUtil::writeStudentToFile(student, outputFile);
                    }
                    outputFile.close();
                    cout << "Student updated successfully." << endl;
                } else {
                    cout << "Update canceled." << endl;
                }
                break;
            }
        }

        if (!found)
        {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }


   

    void deleteStudentById(int id)
    {
        vector<Student> students = FileUtil::readStudentsFromFile("student.txt");
        bool found = false;

        // Iterate through the vector to find the student with the given ID
        for (auto it = students.begin(); it != students.end(); ++it)
        {
            if (it->getId() == id)
            {
                // Display student's information
                it->display();
                // Prompt the user to confirm the deletion
                char confirm;
                cout << "Do you want to delete this student? (y/n): ";
                cin >> confirm;

                if (confirm == 'y' || confirm == 'Y') {
                    students.erase(it); // Erase the student with the given ID
                    found = true;
                    break;
                } else {
                    cout << "Deletion canceled." << endl;
                    return; // Terminate the function without making any changes
                }
            }
        }

        if (found)
        {
            // Rewrite all students to the file, excluding the deleted one
            ofstream outputFile("student.txt");
            for (const auto &student : students)
            {
                FileUtil::writeStudentToFile(student, outputFile);
            }
            outputFile.close();

            cout << "Student with ID " << id << " deleted successfully." << endl;
        }
        else
        {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

    void searchStudents()
    {
        vector<Student> students = FileUtil::readStudentsFromFile("student.txt");
        int choice;

        cout << "Search by:" << endl;
        cout << "1. ID" << endl;
        cout << "2. Name" << endl;
        cout << "3. Sex" << endl;
        cout << "4. Address" << endl;
        cout << "5. Phone Number" << endl;
        cout << "6. Year" << endl;
        cout << "0. Cancel" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0)
        {
            return;
        }

        string searchString;
        cout << "Enter search term: ";
        cin >> searchString;

        // Display matching students
        bool found = false;
        for (const auto &student : students)
        {
            bool match = false;
            switch (choice)
            {
            case 1:
                match = student.getId() == stoi(searchString);
                break;
            case 2:
                match = student.getName() == searchString;
                break;
            case 3:
                match = student.getSex() == searchString;
                break;
            case 4:
                match = student.getAddress() == searchString;
                break;
            case 5:
                match = student.getPhoneNumber() == searchString;
                break;
            case 6:
                match = student.getYear() == stoi(searchString);
                break;
            default:
                cout << "Invalid choice." << endl;
                return;
            }

            if (match)
            {
                student.display();
                found = true;
            }
        }

        if (!found)
        {
            cout << "-------------------" << endl;
            cout << "No matching students found." << endl;
            cout << "-------------------" << endl;
        }
    }
};