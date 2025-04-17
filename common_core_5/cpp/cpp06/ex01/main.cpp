#include <iostream>
#include "Serializer.hpp"

int main()
{
	Data data;
	uintptr_t raw;
	Data *deserialized;

	data.integer = 42;
	data.boolean = true;
	data.string = "So glad I got such a great evaluator";

	std::cout << "Original values: " << std::endl;
	std::cout << " -integer: " << data.integer << std::endl;
	std::cout << " -boolean: " << data.boolean << std::endl;
	std::cout << " -string: " << data.string << std::endl;

	std::cout << "Serializing..." << std::endl;
	raw = Serializer::serialize(&data);

	std::cout << "Serialized value: " << std::endl;
	std::cout << " -" << raw << std::endl;

	std::cout << "Deserializing..." << std::endl;
	deserialized = Serializer::deserialize(raw);

	std::cout << "Deserialized values: " << std::endl;
	std::cout << " -integer: " << deserialized->integer << std::endl;
	std::cout << " -boolean: " << deserialized->boolean << std::endl;
	std::cout << " -string: " << deserialized->string << std::endl;

	return 0;
}