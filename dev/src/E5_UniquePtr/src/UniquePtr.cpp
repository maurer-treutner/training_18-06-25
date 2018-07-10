#include <iostream>
#include <memory>

template <typename T>
auto useVal(const T &x)
{
	auto rv = *x * *x;
	return rv;
}

template <typename T>
auto moveVal(T &&x)
{
	auto rv = std::move(x);
	return *rv * *rv;
}

int main(int argc, char *argv[])
{
	std::cout << "std::unique_ptr Demo" << std::endl;

	auto val = std::make_unique<int>(42);
	std::cout << "val = " << *val << std::endl;
	useVal(val);
	bool isNull = (!val);
	std::cout << "after useVal is_null(val): " << isNull << std::endl;
	moveVal(std::move(val));
	isNull = (!val);
	std::cout << "after moveVal, is_null(val): " << isNull << std::endl;
}