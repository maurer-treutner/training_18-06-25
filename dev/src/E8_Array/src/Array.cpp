#include <iostream>
#include <array>
#include <iterator>

int main(int argc, char *argv[])
{
    std::array<int, 100> nums;

    auto count = 0;
    for (auto &myNum : nums)
    {
        myNum = count * count;
        count++;
    }

    std::copy(std::cbegin(nums), std::cend(nums), std::ostream_iterator<int>(std::cout, "\n"));
}