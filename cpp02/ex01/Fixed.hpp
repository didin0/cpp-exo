#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	public:
		Fixed();
		Fixed(int const number);
		Fixed(float const number);
		~Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& assign);
		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;
	private:
		int fixe;
		static const int rawBits = 8;
};

		std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif
