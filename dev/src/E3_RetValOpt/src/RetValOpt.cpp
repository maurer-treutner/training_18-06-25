#include <iostream>
#include <vector>

#include "CopyCounter.hxx"

CopyCounter getCC2()
{
    return CopyCounter(0);
}

CopyCounter getCC1()
{
    return getCC2();
}

CopyCounter getIndCC1()
{
    CopyCounter c;
    c=getCC2();
    return c;
}


int main(int argc,char *argv[])
{
    CopyCounter c1=getCC1();
    CopyCounter::printCounters("After two returns");
    CopyCounter c2=getIndCC1();
    CopyCounter::printCounters("After indirect return");

}