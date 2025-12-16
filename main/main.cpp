#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <nlohmann/json.hpp>

#include "DataTypes.h"
#include "Utils.h"
#include "DataBase.h"
#include "SavingMessages.h"

using namespace std;

const int USER_LIMIT = 100;

User user[USER_LIMIT];

string get_string(string output) {
    string input;
    cout << "Input " << output << ": ";
    cin >> input;
    return input;
}

class UserFunction : public DataBase {
public:
    UserFunction(User *pUser, int const user_limit) : DataBase(pUser, user_limit) {}

    User current_user;
    User receiver_user;
    bool has_user = false;
    bool has_receiver = false;

    void login(string username, string password) {
        if (!user_exist(username)) {
            cout << "User does not exist!!\n";
            return;
        }
        
        bool can_log_in = check_password(username, password);

        if (!can_log_in) {
            cout << "Incorrect Password!!\n";
            return;
        }

        cout << "Logging in: " << username << endl;
        return;
    }

    bool sign_up(string username, string password) {
        if (user_exist(username)) {
            cout << "Username Unavailable\n";
            return false;
        }

        User the_user = user_return(username);
        the_user.username = username;
        the_user.password = password;
        the_user.is_empty = false;

        update_current_user(the_user);
        return true;
    }

    bool add_friend(string username) {
        current_user.chat_id[receiver_user.username] = create_chat_id(username);
        receiver_user.chat_id[username] = create_chat_id(username);
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
        user[get_index(current_user.username)] = current_user;
        user[get_index(receiver_user.username)] = receiver_user;
    }

private:
    void update_current_user(User the_user) {
        current_user = the_user;
        has_user = true;
    }

    void update_current_receiver(User the_user) {
        receiver_user = the_user;
        has_receiver = true;
    }
};

class ChattingFunction : public UserFunction , public SavingMessages {
public:
    ChattingFunction(User *pUser, int const user_limit, string path) : UserFunction(pUser, user_limit), SavingMessages(path) {}

    int current_id;

    void change_id(int new_id) {
        current_id = new_id;
    }

    bool chatting() {
        if (!has_receiver && !has_user) {
            cout << "Has no user and receiver\n";
            return false;
        }
        if (!has_user) {
            cout << "has_no_user\n";
            return false;
        }
        if (!has_receiver) {
            cout << "has no receiver\n";
            return false;
        }

        string chat;

        while (true) {
            getline(cin, chat);

            save_messsage(current_id, current_user.username, chat, "nigga");

            if (chat == "exit") {
                break;
            }
        }

        return true;
    }
};

class AdminFunction : public DataBase {
public:
    AdminFunction(User *pUser, int const user_limit) : DataBase(pUser, user_limit) {}
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
    User test_user;
    SavingMessages save("message_file");

    test_user.username = "nigga";
    test_user.password = "1234";

    save.save_user(test_user.username, test_user.password);

    return 0;
}
