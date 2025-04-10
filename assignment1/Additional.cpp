#include <cstdio>
#include <iostream>
#include "CDList.h"

using namespace std;

string input_value() {
    string value;
    cout << "Enter any string: ";
    cin >> value;
    return value;
}

int input_method() {
    int num;
    cout << "Select the number" << endl;
    cout << "(0 -> add / 1 -> remove)" << endl;
    cout << "(2 -> forward / 3 -> backward / 4 -> exit)" << endl;
    cin >> num;
    return num;
}

void exe_method(int num, CDList &playList, const string &value) {
    if (num == 0) {
        playList.add(value);
    }
    else if (num == 1) {
        playList.remove();
    }
    else if (num == 2) {
        playList.forward();
    }
    else if (num == 3) {
        playList.backward();
    }
}

int main() {
    CDList playList;
    int num;

    while (true) {
        num = input_method();

        if (num == 4) {
            cout << "exit" << endl;
            break;
        }
        else if (num < 0 || num > 4) {
            cout << "Invalid number input" << endl;
            continue;
        }

        string value = "";
        if (num == 0) {
            value = input_value();
        }

        exe_method(num, playList, value);
        cout << playList << endl;
    }

    return EXIT_SUCCESS;
}
