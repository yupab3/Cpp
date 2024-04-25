#include "Fixed.hpp"

std::ostream& operator<<(std::ostream &out, const Fixed &_Fixed){
	int	Num = _Fixed.getRawBits();
	if (Num % 256 != 0) out << Num / 256.0;
	else out << (Num >> 8);
	return out;
}

Fixed::Fixed(void) :Num(0){
	std::cout << "Default constructor called - " << Num << " \n";
}

Fixed::Fixed(const Fixed &_Fixed) :Num(_Fixed.Num){
	std::cout << "Copy constructor called - " << Num << " \n";
}

Fixed::Fixed(const int _Num) :Num(_Num << 8){
	std::cout << "Copy constructor called - " << Num << " \n";
}

Fixed::Fixed(const float _float){
	int	essence;
	int	decimal = 0;
	float	trgt;
	trgt = roundf(_float * 256.0f) / 256;
	essence = (int)_float;
	trgt = trgt - essence;
	std::cout << trgt << ", " << essence << '\n';
	for (int idx = 1; idx <= 8; idx++){
		trgt = trgt * 2;
		if (trgt >= 1 || trgt <= -1){
			decimal += 256 / pow(2, idx);
			if (trgt >= 1){
				trgt = trgt - 1;
			}
			else{
				trgt = trgt + 1;
			}
		}
	}
	essence = essence << 8;
	if (essence < 0){
		Num = essence - decimal;
	}
	else{
		Num = essence + decimal;
	}
}

Fixed& Fixed::operator=(const Fixed &_Fixed){
	std::cout << "Copy assignment operator called - " << _Fixed.Num << " \n";
	if (this == &_Fixed) return *this;
	Num = _Fixed.Num;
	return *this;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called - " << Num << "\n";
}

int	Fixed::getRawBits(void) const{
	return (Num);
}

void	Fixed::setRawBits(int const raw){
	Num = raw;
}
float Fixed::toFloat( void ) const{
	return (Num / 256.0f);
}

int Fixed::toInt( void ) const{
	return (Num / 256);
}
