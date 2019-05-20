/*************************************************************************
    > File Name: client.cpp
    > Author: ian
    > Mail: ian@taomee.com 
    > Created Time: Fri 17 May 2019 12:25:55 AM CST
 ************************************************************************/

#include<iostream>
#include <fstream>
#include "data.pb.h"

using namespace std;

int main() {
    login::user ian{};
    ian.set_ret(login::user_RET_SUCCESS);

    ian.set_name("summer");
    ian.set_pwd("taomee");
    ian.set_sex(login::user_SEX_MALE);

    auto stat = ian.mutable_me();
    stat->add_photo("18896500132");
    stat->add_photo("18896554954");
    stat->set_addrno(10);
    stat->set_cityno(30);

    std::string buf{};
    ian.SerializeToString(&buf);
    cout << buf << endl;

    ofstream fout;
    fout.open("test", ios::out);
    fout << buf << endl;
    fout.close();

    std::string parse{};
    login::user summer;
    summer.ParseFromString(buf);
    cout << "name:" << summer.name() <<endl;
    cout << "pwd:" << summer.pwd() <<endl;
    login::user::info h = summer.me();
    cout << "cityno:" << h.cityno() <<endl;
    cout << "addrtno:" << h.addrno() <<endl;
    return 0;
}
