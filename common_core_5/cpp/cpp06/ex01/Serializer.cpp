#include "Serializer.hpp"

Serializer::Serializer(){
}

Serializer::Serializer(const Serializer &copy){
	*this = copy;
}

Serializer &Serializer::operator= (const Serializer &a) {
	(void)a;
	return *this;
}

Serializer::~Serializer(){
}
