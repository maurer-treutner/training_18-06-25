#include <iostream>
#include <memory>

auto square(const std::shared_ptr<std::uint32_t>& val)
{
	std::cout<<"val.use_count() = "<<val.use_count()<<std::endl;
	return (*val)*(*val);
}

auto secref_square(std::shared_ptr<std::uint32_t> val)
{
	std::cout<<"val.use_count() = "<<val.use_count()<<std::endl;
	return (*val)*(*val);
}

int main(int argc, char *argv[])
{     
	std::cout << "std::shared_ptr Demo" << std::endl;

	auto myVal = std::make_shared<std::uint32_t>(42);

	std::cout<<"myVal = "<<*myVal<<std::endl;
	std::cout<<"square() = "<<square(myVal)<<std::endl;

	std::cout<<"secref_square() ="<<secref_square(myVal)<<std::endl;
}