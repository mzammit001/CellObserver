#include "StatefulSubject.h"
#include "Observer.h"


StatefulSubject::StatefulSubject(int value)
    : m_state(value)
{
}

StatefulSubject::~StatefulSubject()
{
}

int StatefulSubject::getState() const
{
    return m_state;
}

void StatefulSubject::setState(int value)
{
    m_state = value;
    // notify the observers that the value has changed
    notify();
}

bool StatefulSubject::attach(Observer *o)
{
    m_observers.push_back(o);
    return true;

}

bool StatefulSubject::detach(Observer *o)
{
    m_observers.erase(std::remove(m_observers.begin(), m_observers.end(), o), m_observers.end());
    return true;
}

void StatefulSubject::notify()
{
    for (Observer *o : m_observers) {
        o->update(*this);
    }
}
