//
// Created by Alexandra on 6/18/2021.
//

#pragma once
using namespace std;
#include <vector>
#include <fstream>
#include <string>
#include "Issue.h"
#include "Member.h"

class Repository {

private:
    vector<Issue> issues;
    vector<Member> members;
    void LoadDataIssues();
    void LoadDataMembers();
    void SaveToFile();

public:
    Repository();
    ~Repository();
    vector<Issue>& getIssues();
    vector<Member>& getMembers();
    void addIssue(const Issue& i);
    int checkExistence(Issue i);
    void deleteIssue(const Issue& i);
    void resolveIssue(const Issue& i, const string& name);

};
