#ifndef DATABASE_H
#define DATABASE_H

#include "DataTypes.h"
#include "Utils.h"
#include <bits/stdc++.h>

class DataBase : public Utils {
public:
    DataBase(User *pUser, int const USER_LIMIT) {
        this->pUser = pUser;
        this->USER_LIMIT = USER_LIMIT;
    }

    User *pUser;
    int USER_LIMIT;

    bool check_password(string username, string password) {
        int index = get_index(username);
        if (pUser[index].password == password) {
            return true;
        }
        return false;
    }

    bool user_exist(string username) {
        if (pUser[get_index(username)].is_empty) {
            return false;
        }
        return true;
    }

    User user_return(string username) {
        int index = get_index(username);
        User output = pUser[index];
        return output;
    }

    int get_index(string text) {
        hash<string> hasher;
        int value = hasher(text) % USER_LIMIT;
        return value;
    }
};


#endif