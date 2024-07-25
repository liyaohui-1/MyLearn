#ifndef CONCRETESUBJECT_H_
#define CONCRETESUBJECT_H_

#include <iostream>
#include <list>
#include "Subject.h"
#include "Observer.h"

using namespace std;

//具体被观察者
class ConcreteSubject :public Subject
{
public:
	void Attach(Observer* pObserver)
	{
		cout<<"Attach observer"<< pObserver->name()<<endl;
		m_pObserver_list.push_back(pObserver);
	};
 
	 void Detach(Observer* pObserver) 
	{
		cout<<"Detach observer"<< pObserver->name()<<endl;
		m_pObserver_list.remove(pObserver);
	};
 
	 void Notify()
	{
		for (list<Observer*>::iterator iter = m_pObserver_list.begin(); iter != m_pObserver_list.end(); ++iter)
		{
			(*iter)->Update();
		}
	}
};


#endif