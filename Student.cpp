#pragma once
#include "BadInputException.cpp"
#include <iostream>
#include <iomanip>
using namespace std;

class Student
{
protected:
    string name;
    int id;
    string sex;
    string address;
    string phone_number;
    int year;

public:
    Student()
    {
        name = "Unknown";
        id = 0;
        sex = "Unknown";
        address = "Unknown";
        phone_number = "Unknown";
        year = 0;
    }

    Student(string name, int id, string sex, string address, string phone_number, int year)
    {
        setName(name);
        setId(id);
        setSex(sex);
        setAddress(address);
        setPhoneNumber(phone_number);
        setYear(year);
    }

    void setName(const string name)
    {
        if (!name.empty())
        {
            this->name = name;
        }
        else
        {
            throw BadInputException("Name cannot be empty");
        }
    }

    string getName() const
    {
        return this->name;
    }

    void setId(const int id)
    {
        if (id != 0)
        {
            this->id = id;
        }
        else
        {
            throw BadInputException("ID cannot be zero");
        }
    }

    int getId() const
    {
        return this->id;
    }

    void setSex(const string sex)
    {
        if (!sex.empty())
        {
            this->sex = sex;
        }
        else
        {
            throw BadInputException("Sex cannot be empty");
        }
    }

    string getSex() const
    {
        return this->sex;
    }

    void setAddress(const string address)
    {
        if (!address.empty())
        {
            this->address = address;
        }
        else
        {
            throw BadInputException("Address cannot be empty");
        }
    }

    string getAddress() const
    {
        return this->address;
    }

    void setPhoneNumber(const string phone_number)
    {
        if (!phone_number.empty())
        {
            this->phone_number = phone_number;
        }
        else
        {
            throw BadInputException("Phone number cannot be empty");
        }
    }

    string getPhoneNumber() const
    {
        return this->phone_number;
    }

    void setYear(const int year)
    {
        if (year != 0)
        {
            this->year = year;
        }
        else
        {
            throw BadInputException("Year cannot be zero");
        }
    }

    int getYear() const
    {
        return this->year;
    }

    void display() const
    {
        cout << "-------------------" << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Sex: " << sex << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phone_number << endl;
        cout << "Year: " << year << endl;
        cout << "-------------------" << endl;
    }
};
