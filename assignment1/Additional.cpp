#include <cstdio>
#include <iostream>
#include "CDList.h"

using namespace std;

string input_value() {                  // function to get user input for a node element
    string value;                       // define the variable type is string
    cout << "Enter any string: ";   
    cin >> value;                       // user input the value
    return value;                       // return the value
}

int input_method() {                    // function to select a method (operation) to execute
    int num;
    cout << "Select the number" << endl;
    cout << "(0 -> add / 1 -> remove)" << endl;                                             
    cout << "(2 -> forward / 3 -> backward / 4 -> exit)" << endl;
    cin >> num;                         // user input the method number                
    return num;
}

void exe_method(int num, CDList &playList, const string &value) {
    if (num == 0) {
        playList.add(value);    // input 0 -> add a new node after the cursor
    }
    else if (num == 1) {
        playList.remove();      // input 1 -> remove the node next to the cursor
    }
    else if (num == 2) {
        playList.forward();     // input 2 -> move the cursor to the next node
    }
    else if (num == 3) {
        playList.backward();    // input 3 -> move the cursor to the next node
    }
}

int main() {
    CDList playList;
    int num;

    while (true) {
        num = input_method();

        if (num == 4) {
            cout << "exit" << endl; // input 3 -> break the loop
            break;
        }
        else if (num < 0 || num > 4) {  // if user input other number, then print error message
            cout << "Invalid number input" << endl;
            continue;                   // repeat the loop
        }

        string value = "";              // reset value
        if (num == 0) {
            value = input_value();
        }

        exe_method(num, playList, value);   // execute the selected method
        cout << playList << endl;           // print the list
    }

    getchar();

    return EXIT_SUCCESS;
}
