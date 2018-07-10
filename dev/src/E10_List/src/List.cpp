#include <iostream>
#include <list>
#include <iterator>

int main(int argc, char *argv[])
{
    std::list<std::string> words{"Today", "is", "a", "day"};

    std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;

    auto pos = words.begin();
    pos++;
    pos++;
    pos++;
    words.emplace(pos, "wunderfull");
    words.emplace(pos, "C++");
    std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
}