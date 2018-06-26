#include <iostream>
#include <vector>

#include "CopyCounter.hxx"

void byValue(CopyCounter c)
{
    CopyCounter::printCounters("In function by Value");
}

void byRef(const CopyCounter& c)
{
    CopyCounter::printCounters("In function byRef");
}

void byRValueRef(CopyCounter &&c)
{
    CopyCounter::printCounters("In function byRValueRef");
}

template <typename T>
class Holder
{
public:
    Holder(T *t):
        _t(t)
    {}

    Holder(const Holder &) = delete;

    Holder(Holder &&rhs):
        _t(nullptr)
    {
        swap(_t,rhs._t);
    }

    const Holder & operator = (const Holder &) = delete;

    const Holder & operator = (Holder &&rhs)
    {
        swap(_t,rhs._t);
        return *this;
    }

private:
    T* _t;

};

int main(int argc,char *argv[])
{
    /*
    CopyCounter c1;
    CopyCounter::printCounters("After Creation");
    byValue(c1);
  //  CopyCounter::c
    byRef(c1);
    CopyCounter::

   // CopyCounter c1_copy = c1;
    CopyCounter::printCounters("After Copy");

    CopyCounter c1_moved = std::move(c1);
    CopyCounter::printCounters("After Move");
*/
}