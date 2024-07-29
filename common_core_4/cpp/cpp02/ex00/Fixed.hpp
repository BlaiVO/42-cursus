#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int	value;
		static const int	f_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed &operator= (const Fixed &a);
		~Fixed(void);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif