#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &copy);
		Serializer &operator= (const Serializer &a);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);;
};

#endif