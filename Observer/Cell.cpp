#include "Cell.h"
#include "Subject.h"

Cell::Cell(std::function<int(int)> f)
    : m_cellValue(0), m_func(f)
{
}

Cell::~Cell()
{
}

void Cell::update(const Subject & s)
{
    m_cellValue = s.getState();
}

int Cell::apply() const
{
    return m_func(m_cellValue);
}
