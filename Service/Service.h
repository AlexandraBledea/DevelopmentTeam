//
// Created by Alexandra on 6/18/2021.
//

#pragma once
#include "Repository.h"
#include "Observer.h"


class Service: public Observable {

private:
    Repository& repo;


public:
    Service(Repository& repo);
    ~Service();
    vector<Issue>& getIssues();
    vector<Member>& getMembers();

    vector<Issue> sorted();
    void addIssue(string desc, string status, string reporter, string solver);
    void deleteIssue(Issue i);
    void resolveIssue(Issue i, string name);
};
