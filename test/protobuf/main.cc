#include "test.pb.h"
#include<iostream>
#include <string>
#include <vector>
using namespace fixbug;

int main(){
    GetFriendListsResponse friends;
    User* user1 = friends.add_friend_list();
    user1->set_id(1);
    user1->set_name("zhang san");
    user1->set_sex(User::Man);
    BaseResponse* res = friends.mutable_response();
    res->set_errcode(1);
    res->set_errmsg("OK");
    std::string send_str;
    if(friends.SerializeToString(&send_str))
    {
        std::cout << send_str.c_str() << std::endl;
    }
    return 0;
}