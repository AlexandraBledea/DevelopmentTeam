#include <iostream>
#include <QApplication>
#include "Repository.h"
#include "Service.h"
#include "MemberWindow.h"

int main(int argc, char** argv) {
    QApplication a(argc, argv);

    Repository repository;
    Service service(repository);
    vector<MemberWindow*> windows;
    for(auto & m: service.getMembers()){
        windows.push_back(new MemberWindow(service, m));
    }
    return a.exec();
}
