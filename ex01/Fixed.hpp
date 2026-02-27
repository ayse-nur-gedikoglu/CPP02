#ifndef FIXED_HPP
# define FIXED_HPP

#include <ostream>
class Fixed
{
    private:
        int fixed_point;
        static const int fractional_bits = 8;
    public:
        Fixed();
        Fixed(const int integer);
        Fixed(const float floating_point);
        ~Fixed();
        Fixed(const Fixed &other);
        Fixed &operator=(const Fixed &other);
        
        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);
//std::cout << fixed_objesi yazarsa, ekrana doğrudan bu sayının float halini bas

#endif