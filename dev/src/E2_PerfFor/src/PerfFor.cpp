#include <iostream>
#include <iomanip>
#include <sstream>
#include <memory>

#include "CopyCounter.hxx"

class HexStringStorage
{
  public:
    HexStringStorage() = default;

    template <typename BufType>
    void store(BufType &&buf)
    {
        BufType lbuf = std::forward<BufType>(buf);
        storeHex(lbuf.begin(), lbuf.end());
    }

    template <typename IteratorType>
    void storeHex(IteratorType start, IteratorType end)
    {
        std::ostringstream os;
        constexpr auto hexwidth = 2 * sizeof(*start);
        os << std::setw(hexwidth) << std::setbase(16);
        while (start != end)
        {
            os << static_cast<int>(*start++) << " ";
        }
        _hexString += std::move(os.str());
    }

    auto getString() const
    {
        return _hexString;
    }

  private:
    std::string _hexString;
};

int main(int argc, char *argv[])
{
    HexStringStorage h;
    std::string test = "Alle meine Entchen";
    h.store(test);
    std::cout << h.getString() << std::endl;
    std::cout << "test = " << test << std::endl;
    h.store(std::move(test));
    std::cout << h.getString() << std::endl;
    std::cout << "test = " << test << std::endl;
}