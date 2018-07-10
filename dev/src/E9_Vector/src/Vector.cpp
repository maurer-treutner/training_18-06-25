#include <iostream>
#include <vector>

int main(int argc, char *argv[])
{
    using NumType = std::int64_t;
    std::vector<NumType> lnums;
    std::cout << "Initial Capacity: " << lnums.capacity() << std::endl;
    lnums.reserve(1000);
    std::cout << "Actual Capacity: " << lnums.capacity() << std::endl;
    std::cout << "Actual Size: " << lnums.size() << std::endl;
    NumType fi = 1;
    for (int i = 0; i < lnums.capacity(); i++)
    {
        lnums.emplace_back(fi);
        fi += i;
    }

    std::cout << "Capacity afer filling: " << lnums.capacity() << std::endl;
    std::cout << "Size after filling: " << lnums.capacity() << std::endl;

    lnums.emplace_back(42);

    std::cout << "Capacity afer adding additional element: " << lnums.capacity() << std::endl;
    std::cout << "Size after adding additional element: " << lnums.size() << std::endl;
}