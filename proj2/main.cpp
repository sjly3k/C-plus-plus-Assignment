#include "inf_int.h"

int main()
{
    inf_int a;
    inf_int b("1234812374890471234098212384732184902743748324128374");
    inf_int c("5345896835095438694684509669854906854096872857349857");
    inf_int d("-123847321498032473289421783472837489234723894732984");
    inf_int e("-896783560968354906840968469469468450968549684596948");

    inf_int f(211213213);
    inf_int g(-123213);

    cout << "1. default constructor" << endl;
    cout << a << endl;
    cout << "2. Add operation" << endl;
    cout << "2-1. Positive + Positive : ";
    cout << b+c << endl;
    cout << "2-2. Positive + Negative : ";
    cout << b+d << endl;
    cout << "2-3. Negative + Negative : ";
    cout << d+e << endl;

    cout << "3. Subtraction operation" << endl;
    cout << "3-1. Positive - Positive : ";
    cout << b-c << endl;
    cout << "3-1-1. Positive - Positive (Same number) : ";
    cout << b-b << endl;
    cout << "3-2. Positive - Negative : ";
    cout << b-d << endl;
    cout << "3-3. Negative - Positive : ";
    cout << d-b << endl;
    cout << "3-4. Negative - Negative : ";
    cout << d-e << endl;

    cout << "4. Multiply operation" << endl;
    cout << "4-1. Positive * Positive : ";
    cout << b * c << endl;
    cout << "4-2. Positive * Negative : ";
    cout << b * d << endl;
    cout << "4-3. Negative * Negative : ";
    cout << d * e << endl;
    cout << "4-4. 0 * Positive : ";
    cout << a * b << endl;

    return 0;
}