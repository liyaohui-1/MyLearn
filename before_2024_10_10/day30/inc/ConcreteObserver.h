#ifndef CONCRETEOBSERVER_H_
#define CONCRETEOBSERVER_H_

#include <iostream>
#include "Observer.h"
#include "Subject.h"


using namespace std;

//具体观察者1
class Observer1 :public Observer
{
public:
	Observer1(Subject*pSubject,const string& name="unknown"):Observer(pSubject,name){}
 
	void Update() 
	{
		cout<<"Observer1_"<<m_strName<<"get the upda.new state is:"<<m_pSubject->GetState()<<endl;
	};
};
 
//具体观察者2
class Observer2 :public Observer
{
public:
	Observer2(Subject* pSubject, const string& name = "unknown") :Observer(pSubject, name) {}
 
	void Update()
	{
		cout << "Observer2_" << m_strName << "get the upda.new state is:" << m_pSubject->GetState() << endl;
	};
};

#endif