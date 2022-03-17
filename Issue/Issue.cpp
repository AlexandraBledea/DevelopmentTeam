//
// Created by Alexandra on 6/18/2021.
//

#include "Issue.h"

istream &operator>>(istream &input, Issue &i) {
    input>>i.description>>i.status>>i.reporter>>i.solver;
    return input;
}

ostream &operator<<(ostream &output, const Issue &i) {
    output<<i.description<<" "<<i.status<<" "<<i.reporter<<" "<<i.solver;
    return output;
}

Issue::Issue(string d, string s, string r, string sol): description{d}, status{s}, reporter{r}, solver{sol} {

}

Issue::~Issue() {

}

string Issue::getDescription() {
    return this->description;
}

string Issue::getStatus() {
    return this->status;
}

string Issue::getReporter() {
    return this->reporter;
}

void Issue::setStatus(string status) {
    this->status = status;
}

void Issue::setReporter(string reporter) {
    this->reporter = reporter;
}

string Issue::getSolver() {
    return this->solver;
}

void Issue::setSolver(string solver) {
    this->solver = solver;
}

Issue::Issue() {

}
