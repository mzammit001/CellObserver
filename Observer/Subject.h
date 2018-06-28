#pragma once
#include "Common.h"
#include "Observer.h"

class Subject {
public:
    virtual bool attach(Observer *o) = 0;
    virtual bool detach(Observer *o) = 0;
    virtual void notify() = 0;
    virtual int getState() const = 0;
    virtual void setState(int value) = 0;
};

