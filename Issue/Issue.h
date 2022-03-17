//
// Created by Alexandra on 6/18/2021.
//

#pragma once
using namespace std;
#include <vector>
#include <string>
#include <sstream>

class Issue {

private:
    string description;
    string status;
    string reporter;
    string solver;

public:
    Issue();
    Issue(string d, string s, string r, string sol);
    ~Issue();

    string getDescription();
    string getStatus();
    string getReporter();
    string getSolver();

    void setStatus(string status);
    void setReporter(string reporter);
    void setSolver(string solver);

    friend istream& operator>>(istream&, Issue&);
    friend ostream& operator<<(ostream&, const Issue&);

};


