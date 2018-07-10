#include <iostream>
#include <typeinfo>
#include <type_traits>

template <typename T>
void setByVal(const std::string &vname, T a)
{
    std::cout << "setByValue called with " << vname << " ref:" << std::is_reference<T>::value
              << " const: " << std::is_const<T>::value << std::endl;
}

template <typename T>
void setByRef(const std::string &vname, T &a)
{
    std::cout << "setByRef called with " << vname << " ref:" << std::is_reference<T>::value
              << " const: " << std::is_const<T>::value << std::endl;
}

int main(int argc, char *argv[])
{
    std::string s{"Hello"};
    const std::string cs{"Hello"};
    std::string &rs = s;
    const std::string &crs = s;
    setByVal("s", s);
    setByVal("cs", cs);
    setByVal("rs", rs);
    setByVal("crs", crs);
    setByRef("s", s);
    setByRef("cs", cs);
    setByRef("rs", rs);
    setByRef("crs", crs);
    std::cout << "decltype(s): is ref: " << std::is_reference<decltype(s)>::value
              << " const: " << std::is_const<decltype(s)>::value << std::endl;
    std::cout << "decltype(cs): is ref: " << std::is_reference<decltype(cs)>::value
              << " const: " << std::is_const<decltype(cs)>::value << std::endl;
    std::cout << "decltype(rs): is ref: " << std::is_reference<decltype(rs)>::value
              << " const: " << std::is_const<decltype(rs)>::value << std::endl;
    std::cout << "decltype(crs): is ref: " << std::is_reference<decltype(crs)>::value
              << " const: " << std::is_const<decltype(crs)>::value << std::endl;
}