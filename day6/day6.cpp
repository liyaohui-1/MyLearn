#include <iostream>
#include "json/json.h"

int main()
{
    std::string test ="{\"id\":1,\"name\":\"kurama\"}";
    
    Json::Reader read;
    Json::Value val;

    if(read.parse(test,val))
    {
        int id_index = val["id"].asInt();
        std::string name = val["id"].asString();

        std::cout << "id_index: " << id_index << ",name: " << name <<std::endl;
    }
    

    return 0;
}