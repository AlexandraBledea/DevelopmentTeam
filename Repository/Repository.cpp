//
// Created by Alexandra on 6/18/2021.
//

#include "Repository.h"

void Repository::LoadDataIssues() {
    ifstream inFile("issues.txt");
    Issue currentElement;
    this->issues.clear();
    while(inFile >> currentElement){
        this->issues.push_back(currentElement);
    }
}

void Repository::LoadDataMembers() {
    ifstream inFile("members.txt");
    Member currentElement;
    this->members.clear();
    while(inFile >> currentElement){
        this->members.push_back(currentElement);
    }
}

void Repository::SaveToFile() {
    ofstream OutFile("issues.txt");
    for(auto & i: this->issues){
        OutFile<<i<<'\n';
    }
}

vector<Issue> &Repository::getIssues() {
    return this->issues;
}

vector<Member> &Repository::getMembers() {
    return this->members;
}

Repository::Repository() {
    this->LoadDataMembers();
    this->LoadDataIssues();
}

Repository::~Repository() {

}

void Repository::addIssue(const Issue& i) {
    int pos;
    pos = this->checkExistence(i);
    if(pos==-1){
        this->issues.push_back(i);
        this->SaveToFile();
    }
    else throw exception();
}

int Repository::checkExistence(Issue is) {
    for(int i = 0; i < this->issues.size(); i++)
        if(this->issues[i].getDescription()== is.getDescription())
            return i;
    return -1;
}

void Repository::deleteIssue(const Issue &i) {
    int pos = this->checkExistence(i);
    if(pos != -1){
        this->issues.erase(this->issues.begin()+pos);
        this->SaveToFile();
    }
    else
        throw exception();
}

void Repository::resolveIssue(const Issue &i, const string& name) {
    int pos = this->checkExistence(i);
    this->issues[pos].setStatus("closed");
    this->issues[pos].setSolver(name);
    this->SaveToFile();
}
