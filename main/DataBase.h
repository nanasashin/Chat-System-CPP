#ifndef DATABASE_H
#define DATABASE_H

#include "Utils.h"
#include <bits/stdc++.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class DataBase : public Utils {
public:
    DataBase(string path) {
        this->path = path;
    }

    string path;

    bool save_user(string username, string password) {
        json config;

        ifstream input_file(path + "users.json");
        input_file >> config;
        input_file.close();

        if (user_exist(config, username)) {
            cout << "Username is not available\n";
            return false;
        }

        ofstream output_file(path + "users.json");
        config[username]["password"] = password;

        if (output_file.is_open()) {
            output_file << std::setw(4) << config << endl;
            output_file.close();
        } 
        else {
            cerr << "Error: Unable to open file for writing. (Saving Messages -> save_user)" << endl;
            return false;
        }

        output_file.close();
        return true;
    }

    bool user_exist(json config, string username) {
        if (config.contains(username)) {
            return true;
        }
    }
};


#endif