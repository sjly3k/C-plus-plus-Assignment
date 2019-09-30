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

#ifndef _PROJECT1_MANAGEMENT_H
#define _PROJECT1_MANAGEMENT_H

class studentManagement {
public:
    void Run();
    studentManagement();
    ~studentManagement();

private:
    void Load();
    void Save();
    void ShowAll();
    void ShowAge();
    void ShowName();
    void ShowID();
    void ShowDept();
    void Add();
    int m_index;
    Student stu[STUDENT_MAX];
};

#endif //_PROJECT1_MANAGEMENT_H