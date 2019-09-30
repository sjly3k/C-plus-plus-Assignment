#include "student.h"
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

#define NAME_SIZE 16
#define DEPART_SIZE 21
#define STUDENT_MAX 100

Student::Student() {

}
Student::~Student() {

}
void Student::Add(char *name, int id, int age, char *dept, int tel) {
    strcpy(stuName, name);
    stuID = id;
    stuAge = age;
    strcpy(stuDepartment, dept);
    stuTel = tel;
}
void Student::Input() {

    int name_flag = 0;
    cout << "- Insertion -" << endl;
    cout << "Name ? ";
    while (name_flag != 1) {
        cin.ignore();
        cin.getline(stuName, NAME_SIZE);
        if(strlen(stuName) == 0 || stuName[0] == ' ') {
            name_flag = 1;
        }
        else
            cout << "You have to write down your name." << endl;
    }


    int id_flag = 0;
    cout << "Student ID ? ";
    while (id_flag != 1) {
        cin >> stuID;
        if(GetNumberOfDigits(stuID) == 10) {
            id_flag = 1;
        }
        else
            cout << "You have to write 10 digit ID number." << endl;
    }

    cout << "Age ? ";
    cin >> stuAge;

    int dept_flag = 0;
    cout << "Department ? ";
    while (dept_flag != 1) {
        cin.ignore();
        cin.getline(stuDepartment, NAME_SIZE);
        if(strlen(stuDepartment) == 0 || stuDepartment[0] == ' ') {
            dept_flag = 1;
        }
        else
            cout << "You have to write down your department name." << endl;
    }

    cout << "Tel ? ";
    cin.ignore();
    cin >> stuTel;
}

void Student::Show() {
    cout << stuName << " "
         << stuID << " "
         << stuDepartment << " "
         << stuAge << " 0"
         << stuTel << endl;
}

int Student::getStuIDNum() {
    return stuID;
}
char* Student::getName() {
    return stuName;
}
int Student::getAgeNum() {
    return stuAge;
}
char* Student::getDept() {
    return stuDepartment;
}
int Student::getTel() {
    return stuTel;
}

int Student::setStuIDNum(int stuID) {
    this->stuID = stuID;
}
char* Student::setName(char* stuName) {
    strcpy(this->stuName, stuName);
}
int Student::setAgeNum(int stuAge) {
    this->stuAge = stuAge;
}
char* Student::setDept(char* stuDept) {
    strcpy(this->stuDepartment, stuDept);
}
int Student::setTel(int setTel) {
    this->stuTel = setTel;
}

unsigned Student::GetNumberOfDigits (unsigned i)
{
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}