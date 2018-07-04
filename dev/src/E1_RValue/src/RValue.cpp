#include <iostream>
#include <vector>

#include "CopyCounter.hxx"

void nonMoving(CopyCounter &&c)
{
    c.printCounters("In Nonmoving");
}

void moving(CopyCounter &&c)
{
    CopyCounter localCounter = std::move(c);
}

int main(int argc,char *argv[])
{
    CopyCounter c1;
    CopyCounter::printCounters("After Creation");

    CopyCounter c1_copy = c1;
    CopyCounter::printCounters("After Copy");

    CopyCounter c1_moved = std::move(c1);
    CopyCounter::printCounters("After Move");

    nonMoving(std::move(c1));
    CopyCounter::printCounters("After Call of non moving function");
    // std::move does only a cast operation!

    moving(std::move(c1));
    CopyCounter::printCounters("After Call of moving function");
}