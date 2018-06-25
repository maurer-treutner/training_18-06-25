#include <iostream>
#include <memory>

#include "CopyCounter.hxx"

template <typename T>
class TestHolder
{
public:
    template <typename Arg>
    TestHolder(Arg arg):
        _hold(std::make_shared<T>(arg))
    {}

private:
    std::shared_ptr<T> _hold;
};


int main(int argc,char *argv[])
{
    int num=7;
    auto myHolder = TestHolder<int>(num);
    auto mySuperHolder = TestHolder<int>(42);

}