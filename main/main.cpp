#include <iostream>
#include <bits/stdc++.h>

const int USER_LIMIT = 100;

struct Chat {
    std::string receiver_username;
    std::string user_chat[100];
    std::string receiver_chat[100];
    int chat_handler[200];
};

struct User {
    std::string username;
    std::string password;
    bool is_empty = true;
    std::string friends[100];
    Chat chat[100];
};

User user[USER_LIMIT];

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

    bool check_password(string username, string password) {
        int index = get_index(username);
        if (user[index].password == password) {
            return true;
        }
        return false;
    }

    bool user_exist(string username) {
        if (user[get_index(username)].is_empty) {
            return false;
        }
        return true;
    }
    
    User user_return(string username) {
        int index = get_index(username);
        User output = user[index];
        return output;
    }

    int get_index(string text) {
        hash<string> hasher;
        int value = hasher(text) % USER_LIMIT;
        return value;
    }
};

class Admin : public Utils {

};

class UI : public Utils {
public: 
    User current_user;
private:
    bool login() {
        print_line();

        string username = get_string("Username");

        if (!user_exist(username)) {
            cout << "User does not exist!!\n";
            return false;
        }

        string password = get_string("Password");
        bool can_log_in = check_password(username, password);

        if (!can_log_in) {
            cout << "Incorrect Password!!\n";
            return false;
        }
        
        cout << "Logging In Username: " << username << endl;
        update_current_user(user_return("username"));

        print_line();

        return true;
    }

    bool sign_up() {
        print_line();

        string username = get_string("Username");
        
        if (user_exist(username)) {
            cout << "Username Unavailable\n";
            return false;
        }

        string password = get_string("Password");

        update_current_user(user_return(username));
        update_database_user(username);
        return true;
    }

    bool add_friend() {
        
    }

    User update_current_user(User the_user) {
        current_user = the_user;
    }

    void update_database_user(string username) {
        user[get_index(username)] = current_user;
    }
};

int main() {

    return 0;
}