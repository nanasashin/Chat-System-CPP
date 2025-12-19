#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <nlohmann/json.hpp>

#include "Utils.h"
#include "DataBase.h"
#include "Saving.h"

using namespace std;

string get_string(string output) {
    string input;
    cout << "Input " << output << ": ";
    cin >> input;
    return input;
}

class UserFunction : public DataBase {
public:
    UserFunction(string path) : DataBase(path) {}

    void login(string username, string password) {

    }

    bool sign_up(string username, string password) {

    }

    bool add_friend(string username) {
        return true;
    }

    bool remove_receiver() {
        return true;
    }

    int create_chat_id(string username) {
        hash<string> hasher;
        int value = hasher(username);
        return value;
    }

    void update_database() {
        
    }

private:

};

class ChattingFunction : public UserFunction , public Saving {
public:
    ChattingFunction(string path) : UserFunction(path), Saving(path) {}

    int current_id;

    void change_id(int new_id) {
        current_id = new_id;
    }

    bool chatting() {

    }
};

class AdminFunction : public DataBase {
public:
    AdminFunction(string path) : DataBase(path) {}
};

class UI : public ChattingFunction , public Getting {
public: 
    void main_loop() {
        bool done = false;

        while (true) {
            cout << "[0] Log-in\n";
            cout << "[1] Signup\n";
            cout << "[2] Connect Friend\n";
            cout << "[3] Message\n";
            cout << "[4] Quit\n\n";

            invalid_input:

            switch (get_int("Number")) {
                case 0:
                    break;
                case 1:
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    done = true;
                    break;
                
                default:
                    goto invalid_input;
                    cout << "Invalid Input!!\n";

                    break;
            }    
        }
        
    }

private:
    void login_page() {
        string username = get_string("Username");
        string password = get_string("Password");

        login(username, password);
    }
};

int main() {

    return 0;
}
