#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    private:
        int fixed_point;
        static const int fractional_bits = 8;
    public:
        Fixed(); //default constructor
        ~Fixed(); //destructor
        Fixed(const Fixed &other); //copy constructor
        Fixed &operator=(const Fixed &other); //copy assignment operator
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif