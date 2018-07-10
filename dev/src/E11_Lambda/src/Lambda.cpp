#include <iostream>
#include <functional>
#include <vector>

void callCallback(std::function<void(int)> cb, int val)
{
    std::cout << "callCallback" << std::endl;
    cb(val);
}

class MyClass
{
  public:
    void doCallback(int val)
    {
        std::cout << "MyClass::doCallback(" << val << ")" << std::endl;
    }

    void useCallback(int ival)
    {
        std::cout << "MyClass::useCallback" << std::endl;
        callCallback([this](int v) {
            doCallback(v);
        },
                     ival);
    }
};

int main()
{
    MyClass myClass;
    callCallback([&myClass](int v) { myClass.doCallback(v); }, 4711);
    myClass.useCallback(42);
}
