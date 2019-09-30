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
#include "student.h"
#include "student.cpp"
#include "management.h"
#include "management.cpp"

int main() {
    studentManagement sm;
    sm.Run();
    return 0;
}




