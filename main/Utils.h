#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
using namespace std;

class Utils {
public: 
    void print_line() {
        cout << "---------------------------------------\n";
    }

    string get_string(string output) {
        string input;
        cout << "Input " << output << ": ";
        cin >> input;
        return input;
    }
};

#endif