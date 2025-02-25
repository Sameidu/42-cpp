#include "Serializer.hpp"
#include "Data.hpp"

int main() {
	Data data;
	std::cout << "Data: " << &data << std::endl;
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialize: " << raw << std::endl;
	Data *ptr = Serializer::deserialize(raw);
	std::cout << "Deserialize: " << ptr << std::endl;

	return 0;
}