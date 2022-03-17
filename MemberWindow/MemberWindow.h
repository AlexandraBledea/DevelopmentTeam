//
// Created by Alexandra on 6/18/2021.
//

#pragma once
#include "Observer.h"
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>
#include "TableModel.h"
#include <QTableView>
#include <QVBoxLayout>
#include "Service.h"
#include <QCheckBox>
#include <QSortFilterProxyModel>

class MemberWindow: public  QWidget, public Observer{

private:
    Service& service;
    Member& m;

    TableModel* tableModel;
    QTableView* issuesTableView;
    QLineEdit* issueLineEdit;
    QPushButton* reportButton, *removeButton, *resolveButton;
    QVBoxLayout* mainLayout;
    QGridLayout* buttonsLayout;
    QSortFilterProxyModel* filterModel;


public:
    MemberWindow(Service& service, Member& m);
    ~MemberWindow();
    void initGUI();
    void connectSignals();
    void reportIssue();
    void update() override;
    void notifyModel();
    void removeIssue();
    void check();
    void resolveIssue();
    int getSelectedIndex();

};

