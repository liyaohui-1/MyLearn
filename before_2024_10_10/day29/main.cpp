#include <iostream>
#include "test.h"

using namespace std;

int main(int argc,char *argv[])
{
    cout << "test makefile!" << endl;

    testData T;
    T.SetA(100);

    cout << "m_a: " << T.GetA() << endl;
    
    return 0;
}