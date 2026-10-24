# Student Management System in C++

A menu-driven C++ application designed to manage student records using file handling. The system allows users to add, view, search, update, and delete student information through a simple console interface.

## Features

- **Add Student:** Add a student with a roll number, full name, and course.
- **Display Students:** View all stored student records in a formatted table.
- **Search Student:** Find a student using their roll number.
- **Update Student:** Modify an existing student's name and course.
- **Delete Student:** Remove a student record after confirmation.
- **Count Students:** Display the total number of registered students.
- **Duplicate Prevention:** Prevents multiple records with the same roll number.
- **Input Validation:** Handles invalid numeric inputs and empty text fields.
- **File Handling:** Stores records permanently in a text file.

## Technologies Used

- **Language:** C++
- **Concepts:** Structures, Functions, Vectors, File Handling, Searching, and Data Management
- **Storage:** Text File (`students.txt`)
- **Compiler:** GCC / MinGW or any compatible C++ compiler

## Project Structure

```text
Student-Management-System/
│
├── student_management.cpp
├── students.txt
└── README.md
```

*Note: `students.txt` is created automatically when records are saved.*

## How to Run

### 1. Clone the Repository

```bash
git clone <your-repository-url>
```

### 2. Open the Project Directory

```bash
cd Student-Management-System
```

### 3. Compile the Program

```bash
g++ student_management.cpp -o student_management
```

### 4. Run the Program

**Windows:**
```bash
student_management.exe
```

**Linux / macOS:**
```bash
./student_management
```

## Menu Options

```text
=====================================
      STUDENT MANAGEMENT SYSTEM
=====================================
1. Add Student
2. Display All Students
3. Search Student
4. Update Student
5. Delete Student
6. Count Students
7. Exit
=====================================
Enter your choice:
```

## Data Storage Format

Student records are stored in `students.txt`, with each field separated by a pipe (`|`) character.

Example:

```text
101|Sanjana Mallick|B.Tech CSIT
102|Rahul Sharma|B.Tech CSE
103|Priya Das|BCA
```

## Learning Outcomes

- Understanding structures and user-defined data types in C++.
- Implementing file operations for persistent data storage.
- Using vectors to manage collections of records.
- Applying searching and record-management techniques.
- Handling user input and validating data.

## Future Improvements

- Integrate a database such as MySQL or SQLite.
- Add student marks and grades management.
- Implement login authentication for administrators.
- Export student reports to CSV.
- Add sorting and filtering options.

## Author

**Sanjana Mallick**

B.Tech CSIT (Cybersecurity) Student

## License

This project is available for educational and learning purposes.
