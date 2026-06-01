#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int id;
    string name;
    int marks;
};

Student students[100];
int countStudents = 0;

// Add Student
void addStudent()
{
    cout << "\nEnter Student ID: ";
    cin >> students[countStudents].id;

    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, students[countStudents].name);

    cout << "Enter Student Marks: ";
    cin >> students[countStudents].marks;

    countStudents++;

    cout << "Student Added Successfully!\n";
}

// Display Students
void displayStudents()
{
    if (countStudents == 0)
    {
        cout << "\nNo Records Found!\n";
        return;
    }

    cout << "\nID\tName\t\tMarks\n";
    cout << "---------------------------------\n";

    for (int i = 0; i < countStudents; i++)
    {
        cout << students[i].id << "\t"
             << students[i].name << "\t\t"
             << students[i].marks << endl;
    }
}

// Search Student
void searchStudent()
{
    int id;
    cout << "\nEnter Student ID to Search: ";
    cin >> id;

    for (int i = 0; i < countStudents; i++)
    {
        if (students[i].id == id)
        {
            cout << "\nStudent Found!\n";
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Marks: " << students[i].marks << endl;
            return;
        }
    }

    cout << "Student Not Found!\n";
}

// Update Student
void updateStudent()
{
    int id;
    cout << "\nEnter Student ID to Update: ";
    cin >> id;

    for (int i = 0; i < countStudents; i++)
    {
        if (students[i].id == id)
        {
            cout << "Enter New Name: ";
            cin.ignore();
            getline(cin, students[i].name);

            cout << "Enter New Marks: ";
            cin >> students[i].marks;

            cout << "Record Updated Successfully!\n";
            return;
        }
    }

    cout << "Student Not Found!\n";
}

// Delete Student
void deleteStudent()
{
    int id;
    cout << "\nEnter Student ID to Delete: ";
    cin >> id;

    for (int i = 0; i < countStudents; i++)
    {
        if (students[i].id == id)
        {
            for (int j = i; j < countStudents - 1; j++)
            {
                students[j] = students[j + 1];
            }

            countStudents--;

            cout << "Student Deleted Successfully!\n";
            return;
        }
    }

    cout << "Student Not Found!\n";
}

// Bubble Sort by Marks
void sortStudents()
{
    for (int i = 0; i < countStudents - 1; i++)
    {
        for (int j = 0; j < countStudents - i - 1; j++)
        {
            if (students[j].marks > students[j + 1].marks)
            {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    cout << "Students Sorted by Marks Successfully!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== Student Record Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Sort Students by Marks\n";
        cout << "7. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

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
                sortStudents();
                break;

            case 7:
                cout << "Program Ended.\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}