#include <iostream>
using namespace std;

#include "ConcreteSubject.h"
#include "ConcreteObserver.h"

int main(int argc, char* argv[])
{
    Subject *pSubject=new ConcreteSubject;
	
	Observer *pObserver_1=new Observer1(pSubject,"1");
	Observer *pObserver_2=new Observer1(pSubject,"2");
 
	Observer* pObserver_3 = new Observer2(pSubject, "3");
	Observer* pObserver_4 = new Observer2(pSubject, "4");
	
	//注册观察者
	pSubject->Attach(pObserver_1);
	pSubject->Attach(pObserver_2);
	pSubject->Attach(pObserver_3);
	pSubject->Attach(pObserver_4);
	pSubject->SetState(3);
 
 
 
	pSubject->Notify();
 
 
	return 0;
}