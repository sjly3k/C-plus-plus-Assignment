#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class inf_int {
private:

    char* digits;
    unsigned int length;
    bool thesign;

public:
    inf_int();
    inf_int(int);
    inf_int(const char*);
    inf_int(const inf_int&);//copy
    ~inf_int();
    inf_int& operator=(const inf_int&);

    friend bool operator==(const inf_int&, const inf_int&);
    friend bool operator!=(const inf_int&, const inf_int&);
    friend bool operator>(const inf_int&, const inf_int&);
    friend bool operator<(const inf_int&, const inf_int&);
    friend inf_int operator+(const inf_int&, const inf_int&);
    friend inf_int operator-(const inf_int&, const inf_int&);
    friend inf_int operator*(const inf_int&, const inf_int&);

    friend ostream& operator<<(ostream&, const inf_int&);
    void Add(const char, const unsigned int);
    void Sub(const char, const unsigned int);
    void Mul(const char, const char, const unsigned int);
};
