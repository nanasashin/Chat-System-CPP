#ifndef DATATYPE_H
#define DATATYPE_H

#include <map>
#include <string>

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


#endif