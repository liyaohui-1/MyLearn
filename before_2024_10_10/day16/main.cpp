#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class EA
{
    public:
        enum EA_TYPE
        {
            EA_1 = 1,
            EA_2 = 2,
            EA_3 = 3,
            EA_4 = 4,
            EA_5 = 5,
        };
}; 

int main()
{
    // multimap<int,int> m_key;
    // m_key.insert(make_pair<int,int>(1,1));
    // m_key.insert(make_pair<int,int>(1,2));
    // m_key.insert(make_pair<int,int>(1,3));
    // m_key.insert(make_pair<int,int>(2,5));
    // m_key.insert(make_pair<int,int>(1,4));


    // cout << "m_key.size(): " << m_key.size() << endl;
    // cout << "m_key.(1).size: " << m_key.count(1) << endl;
    // for(auto iter : m_key)
    // {
    //     cout << "first: " << iter.first << ",second: " << iter.second << endl; 
    // }

    // cout << "************************" << endl;

    // unordered_multimap<int,int> m_unorederkey;
    // m_unorederkey.insert(make_pair<int,int>(1,1));
    // m_unorederkey.insert(make_pair<int,int>(1,2));
    // m_unorederkey.insert(make_pair<int,int>(1,3));
    // m_unorederkey.insert(make_pair<int,int>(2,5));
    // m_unorederkey.insert(make_pair<int,int>(1,4));
    // m_unorederkey.insert(make_pair<int,int>(3,6));


    // cout << "m_key.size(): " << m_unorederkey.size() << endl;
    // cout << "m_key.(1).size: " << m_unorederkey.count(1) << endl;
    // for(auto iter : m_unorederkey)
    // {
    //     cout << "first: " << iter.first << ",second: " << iter.second << endl; 
    // }

    // uint32_t xx = 5;

    // cout << "xx: " << xx << ",(EA_TYPE)xx: " << static_cast<EA::EA_TYPE>(xx) << endl;
    // cout << "EA_5:" << EA::EA_5<< endl;
    // cout << "siezof(EA): " << sizeof(EA) << endl;

    // char* str = nullptr;
    // *str;
    // cout << "======================" << endl;

    return 0;
}