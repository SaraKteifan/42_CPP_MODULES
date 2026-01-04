#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class Fixed
{
	private:
		int					value;
		static const int	fractional_bits;
	public:
		Fixed();
		Fixed(const int int_num);
		Fixed(const float float_num);
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		bool	operator>(const Fixed& rhs) const;
		bool	operator<(const Fixed& rhs) const;
		bool	operator>=(const Fixed& rhs) const;
		bool	operator<=(const Fixed& rhs) const;
		bool	operator==(const Fixed& rhs) const;
		bool	operator!=(const Fixed& rhs) const;
		Fixed	operator+(const Fixed& rhs) const;
		Fixed	operator-(const Fixed& rhs) const;
		Fixed	operator*(const Fixed& rhs) const;
		Fixed	operator/(const Fixed& rhs) const;
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
		static Fixed&	min(Fixed& num1, Fixed& num2);
		static const Fixed&	min(const Fixed& num1, const Fixed& num2);
		static Fixed&	max(Fixed& num1, Fixed& num2);
		static const Fixed&	max(const Fixed& num1, const Fixed& num2);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif
