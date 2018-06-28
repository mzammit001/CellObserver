#pragma once

class Subject;

class Observer {
public:
    virtual void update(const Subject& s) = 0;
};
