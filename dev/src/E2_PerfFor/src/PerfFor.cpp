#include <iostream>
#include <memory>

#include "CopyCounter.hxx"

template <typename T>
void perfForward(T &&arg)
{
    moving(std::forward<T>(arg));
}

template <typename T>
void moving(T &&arg)
{
    T local = std::forward<T>(arg);
    local.doSmt();
}

int main(int argc, char *argv[])
{
    CopyCounter cnt1;
    CopyCounter::printCounters("After Creation");
    perfForward(cnt1);
    CopyCounter::printCounters("Forwarded L-Value");
    perfForward(std::move(cnt1));
    CopyCounter::printCounters("Forwarded R-Value");
}