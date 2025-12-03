#include <iostream>
#include <bits/stdc++.h>
#include <map>

const int USER_LIMIT = 100;

struct Chat {
    bool exist = false;
    std::string user_chat[100];
    std::string receiver_chat[100];
    int chat_handler[200];
};

struct User {
    std::string username;
    std::string password;
    bool is_empty = true;
    std::map<std::string, Chat> messages;
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
    bool login(string username, string password) {
        if (!user_exist(username)) {
            cout << "User does not exist!!\n";
            return false;
        }
        
        bool can_log_in = check_password(username, password);

        if (!can_log_in) {
            cout << "Incorrect Password!!\n";
            return false;
        }

        cout << "Logging in: " << username << endl;
        return true;
    }

    bool sign_up(string username, string password) {
        if (user_exist(username)) {
            cout << "Username Unavailable\n";
            return false;
        }

        User the_user = user_return(username);
        the_user.password = password;

        update_current_user(the_user);
        update_database_user(username);
        return true;
    }

    bool add_friend(string username) {
        if (current_user.messages[username].exist) {
            cout << "User is already a friend\n";
            return false;
        }
        current_user.messages[username].exist = true;
        return true;
    }

    bool remove_friend(string username) {
        current_user.messages.erase(username);
    }

    void update_current_user(User the_user) {
        current_user = the_user;
    }

    void update_database_user(string username) {
        user[get_index(username)] = current_user;
    }
};

int main() {

    return 0;
}
