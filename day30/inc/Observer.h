#ifndef OBERSERVER_H_
#define OBERSERVER_H_

#include <string>

class Subject;

using namespace std;

class Observer
{
public:
	
	virtual ~Observer()=default;
		
	Observer( Subject* pSubject,const string &name="unknown"):m_pSubject(pSubject),m_strName(name){}
 
	virtual void Update()=0;
 
	virtual const string& name()
	{
		return m_strName;
	}
 
protected:
	Subject *m_pSubject;
	string m_strName;
};

#endif