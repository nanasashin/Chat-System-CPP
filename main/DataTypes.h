#ifndef DATATYPE_H
#define DATATYPE_H

#include <map>
#include <string>

struct User {
    std::string username;
    std::string password;
    bool is_empty = true;
    std::map<std::string, int> chat_id;
};


#endif