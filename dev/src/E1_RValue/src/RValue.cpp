#include <iostream>
#include <vector>

#include "CopyCounter.hxx"

int main(int argc,char *argv[])
{
    CopyCounter c1;
    CopyCounter::printCounters("After Creation");

    CopyCounter c1_copy = c1;
    CopyCounter::printCounters("After Copy");

    CopyCounter c1_moved = std::move(c1);
    CopyCounter::printCounters("After Move");
}