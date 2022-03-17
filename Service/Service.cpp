//
// Created by Alexandra on 6/18/2021.
//

#include <tuple>
#include "Service.h"

Service::Service(Repository &repo): repo{repo} {

}

Service::~Service() {

}

vector<Issue> &Service::getIssues() {
    return this->repo.getIssues();
}

vector<Member> &Service::getMembers() {
    return this->repo.getMembers();
}

vector<Issue> Service::sorted() {
    vector<Issue> sorted(this->getIssues());
    std::sort(sorted.begin(), sorted.end(),[](Issue& i1, Issue& i2){
       if(i1.getDescription()!=i2.getDescription()) return i1.getDescription() < i2.getDescription();
       return i1.getStatus() < i2.getStatus();
    });
    return sorted;
}

void Service::addIssue(string desc, string status, string reporter, string solver) {
    Issue i(desc, status, reporter, solver);
    this->repo.addIssue(i);
    this->notify();

}

void Service::deleteIssue(Issue i) {
    this->repo.deleteIssue(i);
    this->notify();
}

void Service::resolveIssue(Issue i, string name) {
    this->repo.resolveIssue(i, name);
    this->notify();
}

