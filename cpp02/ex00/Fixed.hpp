#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& assign);
		int getRawBits() const;
		void setRawBits(int const raw);
	private:
		int fixe;
		static const int rawBits = 8;
};

#endif
