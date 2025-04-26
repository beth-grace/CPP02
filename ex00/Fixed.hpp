#pragma once

#include <iostream>

class Fixed
{
private:
    int _fp_number;
    static const int _frac_bits;

public:
    Fixed();
    Fixed(const Fixed &copy);
    ~Fixed();

    Fixed &operator=(const Fixed &src);

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
};