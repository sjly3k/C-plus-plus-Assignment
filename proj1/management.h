//
// Created by User on 28/09/2019.
//

#ifndef _PROJECT1_MANAGEMENT_H
#define _PROJECT1_MANAGEMENT_H

#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include "student.h"

using namespace std;

#define NAME_SIZE 15
#define DEPART_SIZE 20
#define STUDENT_MAX 100

class studentManagement {
public:
    void Run();
    studentManagement();
    virtual ~studentManagement();

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
