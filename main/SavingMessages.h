#ifndef SAVINGMESSAGES_H
#define SAVINGMESSAGES_H

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using namespace std;

using json = nlohmann::json;

class SavingMessages{
public:
    SavingMessages(string path="") {
        this->path = path + "/";
    }

    string path;

    void save_user(string username, string password) {
        json config;

        ifstream input_file(path + "users.json");
        input_file >> config;
        input_file.close();

        ofstream output_file(path + "users.json");
        config[username]["password"] = password;

        if (output_file.is_open()) {
            output_file << std::setw(4) << config << endl;
            output_file.close();
        } 
        else {
            cerr << "Error: Unable to open file for writing. (Saving Messages -> save_user)" << endl;
        }

        output_file.close();
    }

    void save_messsage(int id, string name, string message, string time) {
        ifstream input_file(path + "message.json");
        json config;
        input_file >> config;

        string input = time + "|" + name + ": " + message;

        config[id].push_back(input);
    }
};

#endif
