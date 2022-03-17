//
// Created by Alexandra on 6/18/2021.
//
#pragma once
using namespace std;
#include <vector>
#include <string>
#include <sstream>

class Member {

private:
    string name;
    string type;

public:
    Member();
    Member(string name, string type);
    ~Member();

    string getName();
    string getType();

    friend istream& operator>>(istream&, Member&);

};
