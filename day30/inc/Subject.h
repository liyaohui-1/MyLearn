#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <iostream>
#include <string>
#include <list>
 
class Observer;
 
using namespace std;

class Subject
{
    public:
        Subject():m_nState(0){}
        virtual ~Subject()=default;
    
        //增加观察者
        virtual void Attach(Observer* pObserver)=0;
    
        //移除观察者
        virtual void Detach(Observer* observer)=0;
    
        //通知
        virtual void Notify()=0;
    
        virtual int GetState()
        {
            return m_nState;
        }
    
        void SetState(int state)
        {
            cout<<"Subjeceet updated!"<<endl;
            m_nState	=state;
        }
    protected:
        list<Observer*> m_pObserver_list;
        int m_nState;

};


#endif