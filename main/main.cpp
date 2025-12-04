#include <iostream>

#include "DataTypes.h"
#include "Utils.h"
#include "DataBase.h"

const int USER_LIMIT = 100;

User user[USER_LIMIT];

using namespace std;

class Admin : public DataBase{
    Admin(User *pUser, int const user_limit) : DataBase(pUser, user_limit) {}
};

class UI : public DataBase{
public: 
    UI(User *pUser, int const user_limit) : DataBase(pUser, user_limit) {}

    User current_user;
    User receiver_user;
    bool has_user = false;
    bool has_receiver = false;

    string test (string username) {
        return user_return(username).password;
    }

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
        the_user.username = username;
        the_user.password = password;
        the_user.is_empty = false;

        update_current_user(the_user);
        update_database(current_user.username, receiver_user.username);
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

    bool remove_receiver() {
        current_user.messages.erase(receiver_user.username);
        has_receiver = false;
        return true;
    }

    bool chat_friend(string friend_name) {
        if (!current_user.messages[friend_name].exist) {
            cout << "You don't friend named " << friend_name << endl;
            return false;
        }
        receiver_user = user_return(friend_name);
        return true;
    }

    bool chatting () {
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

        while (true) {
            break;
        }

        return true;
    }

    void update_current_user(User the_user) {
        current_user = the_user;
        has_user = true;
    }

    void update_current_receiver(User the_user) {
        receiver_user = the_user;
        has_receiver = true;
    }

    void update_database(string username, string receiver_name) {
        user[get_index(username)] = current_user;
        user[get_index(receiver_name)] = receiver_user;
    }
};

int main() {
    return 0;
}
