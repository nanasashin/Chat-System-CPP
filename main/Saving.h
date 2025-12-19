#ifndef SAVING_H
#define SAVING_H

#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using namespace std;

using json = nlohmann::json;

class Saving{
public:
    Saving(string path="") {
        this->path = path + "/";
    }

    string path;

    void save_messsage(int id, string name, string message, string time) {
        json config;

        ifstream input_file(path + "users.json");
        input_file >> config;
        input_file.close();

        ofstream output_file(path + "users.json");

        string str_id = to_string(id);

        config[str_id].push_back(time + "| " + name + ": " + message);

        if (output_file.is_open()) {
            output_file << std::setw(4) << config << endl;
            output_file.close();
        } 
        else {
            cerr << "Error: Unable to open file for writing. (Saving Messages -> save_messages)" << endl;
        }

        output_file.close();
    }
};

#endif
