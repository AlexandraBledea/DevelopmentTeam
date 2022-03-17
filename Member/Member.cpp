//
// Created by Alexandra on 6/18/2021.
//

#include "Member.h"

istream &operator>>(istream &input, Member &m) {
    input>>m.name>>m.type;
    return input;
}

Member::Member(string name, string type): name{name}, type{type} {

}

Member::~Member() {

}

string Member::getName() {
    return this->name;
}

string Member::getType() {
    return this->type;
}

Member::Member() {

}
