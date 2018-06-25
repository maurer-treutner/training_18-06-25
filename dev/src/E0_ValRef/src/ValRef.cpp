#include <iostream>
#include <vector>

#include "CopyCounter.hxx"

void demoByValue(CopyCounter cnt)
{   
    CopyCounter::printCounters("demoByValue");
}

void demoByReference(const CopyCounter& cnt)
{
    CopyCounter::printCounters("demoByReference");
}

int main(int argc,char *argv[])
{
    CopyCounter myCounter;
    CopyCounter::printCounters("After Construction");

    demoByValue(myCounter);
    CopyCounter::printCounters("After demoByValue");

    demoByReference(myCounter);
    CopyCounter::printCounters("After demoByReference");
}