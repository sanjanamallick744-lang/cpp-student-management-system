#include <iostream>
#include <fstream>
using namespace std;

struct Student
{
    int roll;
    char name[30];
};

int main()
{
    Student s;
    int choice, searchRoll;
    bool found;

    do
    {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                ofstream file("students.txt", ios::app);

                cout << "Enter Roll No: ";
                cin >> s.roll;

                cout << "Enter Name: ";
                cin >> s.name;

                file << s.roll << " " << s.name << endl;
                file.close();

                cout << "Student Added Successfully!\n";
                break;
            }

            case 2:
            {
                ifstream file("students.txt");

                cout << "\nRoll No\tName\n";

                while(file >> s.roll >> s.name)
                {
                    cout << s.roll << "\t" << s.name << endl;
                }

                file.close();
                break;
            }

            case 3:
            {
                cout << "Enter Roll No to Search: ";
                cin >> searchRoll;

                ifstream file("students.txt");
                found = false;

                while(file >> s.roll >> s.name)
                {
                    if(s.roll == searchRoll)
                    {
                        cout << "\nStudent Found!";
                        cout << "\nRoll No: " << s.roll;
                        cout << "\nName: " << s.name << endl;

                        found = true;
                        break;
                    }
                }

                if(!found)
                {
                    cout << "\nStudent Not Found!";
                }

                file.close();
                break;
            }

            case 4:
                cout << "\nThank You!";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 4);

    return 0;
}
