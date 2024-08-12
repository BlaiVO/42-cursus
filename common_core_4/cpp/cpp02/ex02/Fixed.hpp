#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	private:
		int	value;
		static const int	f_bits = 8;
	public:
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed &copy);
		~Fixed(void);
		Fixed &operator= (const Fixed &a);
		int operator> (const Fixed &a);
		int operator< (const Fixed &a);
		int operator>= (const Fixed &a);
		int operator<= (const Fixed &a);
		int operator== (const Fixed &a);
		int	operator!= (const Fixed &a);
		Fixed	operator+ (const Fixed &a);
		Fixed	operator- (const Fixed &a);
		Fixed	operator* (const Fixed &a);
		Fixed	operator/ (const Fixed &a);
		Fixed	&operator++ ();
		Fixed	operator++(int);
		Fixed	&operator-- ();
		Fixed	operator--(int);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed &min(Fixed &f1, Fixed &f2);
		static const Fixed	&min(const Fixed &f1, const Fixed &f2);
		static Fixed &max(Fixed &f1, Fixed &f2);
		static const Fixed	&max(const Fixed &f1, const Fixed &f2);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &fixed);

#endif
