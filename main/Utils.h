#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class Utils {
public: 
    void print_line() {
        cout << "---------------------------------------\n";
    }

    string get_time() {
        return "1: 00";                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
    }
};

class Getting {
public:
    string get_string(string output) {
        string input;
        cout << "Input " << output << ": ";
        cin >> input;
        return input;
    }

    int get_int(string output) {
        int input;
        cout << "Input " << output << ": ";
        cin >> input;
        return input;
    }
};

#endif