#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
    int x, y;
    cout << "please enter two numbers: ";
    cin >> x >> y;
    int sum = x + y;

    cout << "There sum is " << sum << endl;

    return EXIT_SUCCESS;
}