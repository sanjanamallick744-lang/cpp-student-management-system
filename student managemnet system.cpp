
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <limits>
using namespace std;

struct Student
{
    int roll;
    string name;
    string course;
};

const string FILE_NAME = "students.txt";

// Read all student records from file
vector<Student> loadStudents()
{
    vector<Student> students;
    ifstream file(FILE_NAME.c_str());
    Student s;
    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string rollText;

        if (getline(ss, rollText, '|') &&
            getline(ss, s.name, '|') &&
            getline(ss, s.course, '|'))
        {
            stringstream converter(rollText);

            if (converter >> s.roll)
                students.push_back(s);
        }
    }

    file.close();
    return students;
}

// Save all student records to file
bool saveStudents(const vector<Student>& students)
{
    ofstream file(FILE_NAME.c_str());

    if (!file)
    {
        cout << "\nError: Unable to save student records!\n";
        return false;
    }

    for (size_t i = 0; i < students.size(); i++)
    {
        file << students[i].roll << "|"
             << students[i].name << "|"
             << students[i].course << "\n";
    }

    file.close();
    return true;
}

// Find student index by roll number
int findStudent(const vector<Student>& students, int roll)
{
    for (size_t i = 0; i < students.size(); i++)
    {
        if (students[i].roll == roll)
            return (int)i;
    }

    return -1;
}

// Read a valid integer
int readInt(string message)
{
    string input;
    int value;
    char extra;

    while (true)
    {
        cout << message;
        getline(cin, input);

        stringstream ss(input);

        if (ss >> value && !(ss >> extra))
            return value;

        cout << "Invalid input! Please enter a number.\n";
    }
}

// Read non-empty text without the file delimiter
string readText(string message)
{
    string text;

    while (true)
    {
        cout << message;
        getline(cin, text);

        if (text.find('|') != string::npos)
        {
            cout << "The character '|' is not allowed.\n";
        }
        else if (text.find_first_not_of(" \t") == string::npos)
        {
            cout << "Input cannot be empty!\n";
        }
        else
        {
            return text;
        }
    }
}

// Add a student
void addStudent()
{
    vector<Student> students = loadStudents();
    Student s;

    cout << "\n--- ADD STUDENT ---\n";

    s.roll = readInt("Enter Roll Number: ");

    if (s.roll <= 0)
    {
        cout << "Roll number must be positive!\n";
        return;
    }

    if (findStudent(students, s.roll) != -1)
    {
        cout << "Error: Roll number already exists!\n";
        return;
    }

    s.name = readText("Enter Full Name: ");
    s.course = readText("Enter Course: ");

    students.push_back(s);

    if (saveStudents(students))
        cout << "\nStudent added successfully!\n";
}

// Display all students
void displayStudents()
{
    vector<Student> students = loadStudents();

    cout << "\n========== STUDENT RECORDS ==========\n";

    if (students.empty())
    {
        cout << "No student records found.\n";
        return;
    }

    cout << left
         << setw(12) << "Roll No"
         << setw(30) << "Name"
         << "Course\n";

    cout << string(65, '-') << "\n";

    for (size_t i = 0; i < students.size(); i++)
    {
        cout << left
             << setw(12) << students[i].roll
             << setw(30) << students[i].name
             << students[i].course << "\n";
    }

    cout << "\nTotal Students: " << students.size() << "\n";
}

// Search a student
void searchStudent()
{
    vector<Student> students = loadStudents();

    cout << "\n--- SEARCH STUDENT ---\n";

    int roll = readInt("Enter Roll Number: ");
    int index = findStudent(students, roll);

    if (index == -1)
    {
        cout << "Student not found!\n";
        return;
    }

    cout << "\nStudent Found!\n";
    cout << "Roll Number: " << students[index].roll << "\n";
    cout << "Name       : " << students[index].name << "\n";
    cout << "Course     : " << students[index].course << "\n";
}

// Update student details
void updateStudent()
{
    vector<Student> students = loadStudents();

    cout << "\n--- UPDATE STUDENT ---\n";

    int roll = readInt("Enter Roll Number: ");
    int index = findStudent(students, roll);

    if (index == -1)
    {
        cout << "Student not found!\n";
        return;
    }

    cout << "Current Name: " << students[index].name << "\n";
    cout << "Current Course: " << students[index].course << "\n";

    students[index].name = readText("Enter New Name: ");
    students[index].course = readText("Enter New Course: ");

    if (saveStudents(students))
        cout << "Student details updated successfully!\n";
}

// Delete a student
void deleteStudent()
{
    vector<Student> students = loadStudents();

    cout << "\n--- DELETE STUDENT ---\n";

    int roll = readInt("Enter Roll Number: ");
    int index = findStudent(students, roll);

    if (index == -1)
    {
        cout << "Student not found!\n";
        return;
    }

    cout << "Student: " << students[index].name << "\n";

    cout << "Are you sure you want to delete? (y/n): ";
    string confirm;
    getline(cin, confirm);

    if (confirm != "y" && confirm != "Y")
    {
        cout << "Deletion cancelled.\n";
        return;
    }

    students.erase(students.begin() + index);

    if (saveStudents(students))
        cout << "Student deleted successfully!\n";
}

// Main menu
int main()
{
    int choice;

    do
    {
        cout << "\n";
        cout << "=====================================\n";
        cout << "      STUDENT MANAGEMENT SYSTEM\n";
        cout << "=====================================\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Count Students\n";
        cout << "7. Exit\n";
        cout << "=====================================\n";

        choice = readInt("Enter your choice: ");

        switch (choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
            {
                vector<Student> students = loadStudents();
                cout << "\nTotal Students: "
                     << students.size() << "\n";
                break;
            }

            case 7:
                cout << "\nThank you for using the system!\n";
                break;

            default:
                cout << "Invalid choice! Select 1 to 7.\n";
        }

    } while (choice != 7);

    return 0;
}
