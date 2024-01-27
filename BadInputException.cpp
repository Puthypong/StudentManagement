#pragma once
#include <iostream>
#include <exception>
#include <string>

using namespace std;

class BadInputException : public exception {
private:
    string field;

public:
    BadInputException(const string& field) : field(field) {}

    const char* what() const throw () {
        string message = "Error: bad input in field '" + field + "'";
        return message.c_str();
    }
};
