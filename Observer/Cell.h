#pragma once
#include "Common.h"
#include "Observer.h"

class Subject;

class Cell : public Observer
{
private:
    int m_cellValue;
    std::function<int(int)> m_func;

public:
    Cell(std::function<int(int)> f);
    ~Cell();

    virtual void update(const Subject& s) override;
    int apply() const;
};

