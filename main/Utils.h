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
        time_t now = time(0); 
        char* dt_string = ctime(&now); 
        return dt_string;
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