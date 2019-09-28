//
// Created by User on 28/09/2019.
//

#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include "student.h"
#include "management.h"
using namespace std;

#define NAME_SIZE 15
#define DEPART_SIZE 20
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

    cout << "Name ? ";
    cin.ignore();
    cin.getline(stuName, NAME_SIZE);
    cout << "Student ID ?";
    cin >> stuID;
    cout << "Age ? ";
    cin >> stuAge;
    cout << "Department ? ";
    cin.ignore();
    cin.getline(stuDepartment, DEPART_SIZE);
    cout << "Tel ?";
    cin >> stuTel;
}

void Student::Show() {
    cout << stuName << " "
         << stuID << " "
         << stuDepartment << " "
         << stuAge << " "
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


