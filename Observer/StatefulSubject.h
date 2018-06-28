#pragma once
#include "Subject.h"
#include "Common.h"

class Observer;

class StatefulSubject : public Subject
{
private:
    std::vector<Observer *> m_observers;
    int m_state;

public:
    StatefulSubject(int value = 0);
    ~StatefulSubject();

    virtual int getState() const override;
    virtual void setState(int value) override;

    virtual bool attach(Observer *o) override;
    virtual bool detach(Observer *o) override;
    virtual void notify() override;
};

