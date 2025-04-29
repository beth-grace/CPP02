#pragma once

#include <cmath>
#include <iostream>

class Fixed
{
    private:
        int _fp_number;
        static const int _frac_bits;

    public:
        Fixed();
        Fixed(const int input);
        Fixed(const float input);
        Fixed(const Fixed &copy);
        ~Fixed();

        Fixed &operator=(const Fixed &src);

        bool operator>(Fixed fixed)const;
		bool operator<(Fixed fixed)const;
		bool operator>=(Fixed fixed)const;
		bool operator<=(Fixed fixed)const;
		bool operator==(Fixed fixed)const;
		bool operator!=(Fixed fixed)const;

		// Arithmetic Operators
		Fixed operator+(Fixed fixed)const;
		Fixed operator-(Fixed fixed)const;
		Fixed operator*(Fixed fixed)const;
		Fixed operator/(Fixed fixed)const;

		// pre-increment Operators
		Fixed operator++();
		Fixed operator--();
		// post-increment Operators
		Fixed operator++(int);
		Fixed operator--(int);

        float   toFloat(void)const;
        int     toInt(void)const;

        int     getRawBits(void) const;
        void    setRawBits(int const raw);

        static  Fixed &min(Fixed &first, Fixed &second);
        static  const Fixed &min(Fixed const &first, Fixed const &second);
        static  Fixed &max(Fixed &first, Fixed &second);
        static  const Fixed &max(Fixed const &first, Fixed const &second);
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);