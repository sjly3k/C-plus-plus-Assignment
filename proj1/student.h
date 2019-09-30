#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

#define NAME_SIZE 16
#define DEPART_SIZE 21
#define STUDENT_MAX 100

#ifndef _PROJECT1_STUDENT_H
#define _PROJECT1_STUDENT_H

class Student {
public:
    void Input();
    void Show();
    void Add(char *name, int id, int age, char *dept, int tel);
    Student();
    ~Student();
    char* getDept(); // 전공 가져올 때
    char* getName(); // 이름 가져올 때
    int getStuIDNum(); // 학번 가져올 때
    int getAgeNum(); // 나이 가져올 때
    int getTel();
    char* setDept(char*); // 전공 가져올 때
    char* setName(char*); // 이름 가져올 때
    int setStuIDNum(int); // 학번 가져올 때
    int setAgeNum(int); // 나이 가져올 때
    int setTel(int);
    unsigned GetNumberOfDigits(unsigned);
private:
    char stuName[NAME_SIZE];
    char stuDepartment[DEPART_SIZE];
    int stuID;
    int stuAge;
    int stuTel;
};

#endif //_PROJECT1_STUDENT_H