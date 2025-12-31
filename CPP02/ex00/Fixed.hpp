#ifndef FIXED_H
# define FIXED_H

class Fixed
{
	private:
		int					value;
		static const int	bits_num;
	public:
		Fixed();
		Fixed(/* arg */);
		/* More constructors*/
		~Fixed();
		int	getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif