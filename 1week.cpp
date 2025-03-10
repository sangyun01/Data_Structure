#include <cstdlib>
#include <iostream>

using namespace std;

enum Day
{
    SUN,
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT
};

int main() {
    int x, y;
    cout << "please enter two numbers: ";
    cin >> x >> y;
    int sum = x + y;

    Day today = THU;

    cout << "There sum is " << sum << endl;
    cout << today << endl;

    return EXIT_SUCCESS;
}