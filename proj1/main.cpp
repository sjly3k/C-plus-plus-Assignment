#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>

using namespace std;

#define NAME_SIZE 15
#define DEPART_SIZE 50
#define STUDENT_MAX 100

class Student {
public:
    void Input();
    void Show();
    void Add(char *name, int id, int age, char *dept, int tel);
    Student();
    virtual ~Student();
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
private:
    char stuName[NAME_SIZE];
    char stuDepartment[DEPART_SIZE];
    int stuID;
    int stuAge;
    int stuTel;
};

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

studentManagement::studentManagement() {
    m_index = 0;
}
studentManagement::~studentManagement() {

}

void studentManagement::Run() {

    int n;
    Load();
    tryAgain :
    while(1) {

        cout << "1. Insertion" << endl;
        cout << "2. Search" << endl;
        cout << "3. Exit" << endl;
        cout << "> ";

        cin >> n;

        switch (n) {

            case 1:
                Add();
                break;
            case 2:
                while (1) {

                    cout << "1. Search by name" << endl;
                    cout << "2. Search by student ID (10 numbers)" << endl;
                    cout << "3. Search by department name" << endl;
                    cout << "4. Search by Age" << endl;
                    cout << "5. List All" << endl;
                    cout << "6. Go to Main Menu" << endl;
                    cout << " > ";

                    int iChoice_search;
                    cin >> iChoice_search;

                    switch (iChoice_search) {
                        case 1: ShowName(); break;
                        case 2: ShowID(); break;
                        case 3: ShowDept(); break;
                        case 4: ShowAge(); break;
                        case 5: ShowAll(); break;
                        case 6: goto tryAgain;
                    }
                }
            case 3:
                Save();
                exit(0);
        }

    }
}

void studentManagement::Add() {

    stu[m_index].Input();
    m_index++;
    cout << "Student Info Input Complete" << endl;
}


bool sortByName (Student &A, Student &B)
{
    string first_stu_name = A.getName();
    string second_stu_name = B.getName();
    return first_stu_name.compare(second_stu_name) < 0;
}

void studentManagement::ShowAll() {

    vector<Student> temp;
    Student stu_temp[m_index];
    for (int i = 0; i <m_index; i++) {
        temp.push_back(stu[i]);
    }

    sort(temp.begin(), temp.end(), sortByName);
    copy(temp.begin(), temp.end(), stu_temp);
    cout << "Name      StudentID      Dept      Age      Tel" << endl;
    for (int i = 0; i < m_index; i++) {
        stu_temp[i].Show();
    }
}

void studentManagement::ShowAge() {

    vector<Student> temp;
    Student stu_temp[m_index];
    for (int i = 0; i < m_index; i++) {
        temp.push_back(stu[i]);
    }

    sort(temp.begin(), temp.end(), sortByName);
    copy(temp.begin(), temp.end(), stu_temp);

    cout << "Age keyword? ";
    int tmp_age;
    cin >> tmp_age;
    int flag = 0;

    cout << "Name      StudentID      Dept      Age      Tel" << endl;
    for (int i = 0; i < m_index; i++) {
        if (stu_temp[i].getAgeNum() == tmp_age) {
            stu_temp[i].Show();
            flag = 1;
        }
    }

    if (flag == 0) {
        cout << "Age : " << tmp_age << " doesn't exist." << endl;
    }
}

void studentManagement::ShowID() {

    vector<Student> temp;
    Student stu_temp[m_index];
    for (int i = 0; i <m_index; i++) {
        temp.push_back(stu[i]);
    }

    sort(temp.begin(), temp.end(), sortByName);
    copy(temp.begin(), temp.end(), stu_temp);

    cout << "ID keyword? ";
    int tmp_id;
    cin >> tmp_id;
    int flag = 0;

    cout << "Name      StudentID      Dept      Age      Tel" << endl;
    for (int i = 0; i < m_index; i++) {
        if (stu_temp[i].getStuIDNum() == tmp_id) {
            stu_temp[i].Show();
            flag = 1;
        }
    }

    if (flag == 0) {
        cout << "ID : " << tmp_id << " doesn't exist." << endl;
    }
}

void studentManagement::ShowName() {

    vector<Student> temp;
    Student stu_temp[m_index];
    for (int i = 0; i < m_index; i++) {
        temp.push_back(stu[i]);
    }

    sort(temp.begin(), temp.end(), sortByName);
    copy(temp.begin(), temp.end(), stu_temp);

    cout << "Name keyword? ";
    char tmp_name[NAME_SIZE];
    cin.ignore();
    cin.getline(tmp_name, NAME_SIZE);
    int flag = 0;

    cout << "Name      StudentID      Dept      Age      Tel" << endl;
    for (int i = 0; i < m_index; i++) {
        if (strcmp(stu_temp[i].getName(), tmp_name) == 0) {
            stu_temp[i].Show();
            flag = 1;
        }
    }

    if (flag == 0) {
        cout << "Name : " << tmp_name << " doesn't exist." << endl;
    }
}

void studentManagement::ShowDept() {

    vector<Student> temp;
    Student stu_temp[m_index];
    for (int i = 0; i < m_index; i++) {
        temp.push_back(stu[i]);
    }

    sort(temp.begin(), temp.end(), sortByName);
    copy(temp.begin(), temp.end(), stu_temp);

    cout << "Department keyword? ";
    char tmp_dept[DEPART_SIZE];
    cin.ignore();
    cin.getline(tmp_dept, DEPART_SIZE);
    int flag = 0;

    cout << "Name      StudentID      Dept      Age      Tel" << endl;
    for (int i = 0; i < m_index; i++) {
        if (strcmp(stu_temp[i].getDept(), tmp_dept) == 0) {
            stu_temp[i].Show();
            flag = 1;
        }
    }

    if (flag == 0) {
        cout << "Dept : " << tmp_dept << " doesn't exist." << endl;
    }
}

void studentManagement::Save() {
    ofstream outFile("file1.dat");
    for (int i = 0; i< m_index; i++) {
        outFile << stu[i].getName() << '\n' << stu[i].getStuIDNum() << '\n'
                << stu[i].getDept() << '\n' << stu[i].getAgeNum() << '\n' << "0" << stu[i].getTel() << "\n" << "-" << endl;
    }
    outFile.close();
}

void studentManagement::Load() {
    ifstream inFile;
    inFile.open("file1.dat");
    if (!inFile) {
        cout << "File is not exist. Press any key...";
        cin.ignore();
        cin.get();
        return;
    }
    char tmp_name[NAME_SIZE];
    char tmp_dept[DEPART_SIZE];
    int tmp_id;
    int tmp_age;
    int tmp_tel;

    vector<string> stu_vec;
    while(inFile.good()) {
        string substr;
        getline(inFile, substr);
        stu_vec.push_back(substr);
    }

    inFile.close();

    for(int i = 0; i<stu_vec.size(); i++) {

        if (stu_vec[i].compare("-") == 0) {
            m_index++;
        }

        if (i % 6 == 0) {
            strcpy(tmp_name, stu_vec[i].c_str());
            stu[m_index].setName(tmp_name);
        } else if (i % 6 == 1) {
            tmp_id = atoi(stu_vec[i].c_str());
            stu[m_index].setStuIDNum(tmp_id);
        } else if (i % 6 == 2) {
            strcpy(tmp_dept, stu_vec[i].c_str());
            stu[m_index].setDept(tmp_dept);
        } else if (i % 6 == 3) {
            tmp_age = atoi(stu_vec[i].c_str());
            stu[m_index].setAgeNum(tmp_age);
        } else if (i % 6 == 4) {
            tmp_tel = atoi(stu_vec[i].c_str());
            stu[m_index].setTel(tmp_tel);
        }
    }
}

int main() {
    studentManagement sm;
    sm.Run();
    return 0;
}




