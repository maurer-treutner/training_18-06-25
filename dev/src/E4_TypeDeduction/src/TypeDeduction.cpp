#include <functional>
#include <iostream>
#include <vector>

int &f()
{
    static auto val=0;
    return val;
}

void doCallback(std::function<int &()> cb)
{
    std::cout<<"Callback: "<<cb()<<std::endl;
}

int main(int argc,char *argv[])
{
    const auto val = 42;
    std::cout<<"val="<<val<<std::endl;

    auto i = val;
    i++;

    auto &ri = i;
    ri = 4711;
    std::cout<<"i = "<<i<<std::endl;

    auto j = ri;
    j = 42;
    std::cout<<"i = "<<i<<std::endl;

    auto & f1 = f();
    ++f1;

    auto f2 = f();
    std::cout<<"f2 = "<<f2<<std::endl;

    auto myFunction = f;
    auto f3 = myFunction();

    std::cout<<"f3 = "<<f3<<std::endl;

    doCallback(myFunction);

}