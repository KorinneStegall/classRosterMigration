## Student System Migration

### Description:
This project involves migrating an existing student system for a university to a new platform using the C++ language. The existing system's requirements are outlined, and the contractor (you) is tasked with implementing a part of the system based on these requirements. The part to be implemented involves reading and manipulating student data.

### Files Included:
1. degree.h: Contains the definition of an enumerated data type DegreeProgram for the degree programs (SECURITY, NETWORK, SOFTWARE).
2. student.h and student.cpp: Define the Student class with variables and functions to manage student data.
3. roster.h and roster.cpp: Define the Roster class with functions to manage a roster of students.
4. main.cpp: Contains the main() function to demonstrate the required functionality.

### Requirements:
A. Modify the “studentData Table” to include your personal information as the last item.

B. Create a C++ project with six source code files as specified.

C. Define an enumerated data type DegreeProgram in degree.h.

D. Implement the Student class with specified variables and functions.

E. Implement the Roster class to manage student data

F. Demonstrate the program’s functionality by adding a main() function in main.cpp.

G. Ensure professional communication in the content and presentation of the submission.


### Implementation:
1. Student Class (student.h, student.cpp):
    * Defines the Student class with necessary variables and functions.
    * Variables include student ID, first name, last name, email address, age, days to complete each course, and degree program.
    * Functions include accessors, mutators, constructor, and print function.
2. Roster Class (roster.h, roster.cpp):
    * Defines the Roster class to manage a list of students.
    * Uses an array of pointers (classRosterArray) to hold student data.
    * Functions include adding/removing students, printing all student data, calculating average days in course, validating email addresses, and printing by degree program.
3. Main Function (main.cpp):
    * Demonstrates the required functionality as specified in the requirements.
    * Creates an instance of the Roster class and adds students.
    * Prints all student data, checks for invalid email addresses, calculates average days in course, prints students by degree program, and removes students by ID.
    * Implements the destructor to release dynamically allocated memory.
