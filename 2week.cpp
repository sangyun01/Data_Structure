#include <cstdlib>
#include <iostream>

using namespace std;

enum Day
{
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

int a[] = {0, 1, 2, 3};

int main() {
    Day Today = Saturday; // Saturday = 6

    if (Today == 6 || Today ==0) {
        cout << "It's a weekend!" << endl;
    }

    switch(Today) {
        case Sunday:
            cout << "Today is Sunday" << endl;
            break;
        case Monday:
            cout << "Today is Monday" << endl;
            break;
        case Tuesday:
            cout << "Today is Tuesday" << endl;
            break;
        case Wednesday:
            cout << "Today is Wednesday" << endl;
            break;
        case Thursday:
            cout << "Today is Thursday" << endl;
            break;
        case Friday:
            cout << "Today is Friday" << endl;
            break;
        case Saturday:
            cout << "Today is Saturday" << endl;
            break;
        default:
            cout << "Invalid day!" << endl;
    }

    cout << "Numerical value of today : " << Today << endl;

    int i = 2;
    int j = i++;
    cout << j << endl;
    int k = --i;
    cout << k << a[k++] << endl;

    return EXIT_SUCCESS;
}