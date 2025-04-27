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

        float   toFloat(void)const;
        int     toInt(void)const;

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};

std::ostream    &operator<<(std::ostream &o, Fixed const &fixed);