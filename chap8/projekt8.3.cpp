#include <iostream>
#include <cmath>

class Complex
{
	public:
		Complex(const double real = 0,const double imaginary = 0) : _real(real),_imaginary(imaginary) {}
		friend std::istream& operator >>(std::istream& input,Complex& complex)
		{
			double real,imaginary;
			char plus,i;
			input >> real;
			input >> plus;
			input >> imaginary;
			input >> i;
			if (plus == '+' && i == 'i')
			{
				complex._real = real;
				complex._imaginary = imaginary;
			}
			return input;
		}
		friend std::ostream& operator <<(std::ostream& output,const Complex& complex)
		{
			output << complex._real << "+" << complex._imaginary << "i";
			return output;
		}
		const double absoluteValue(void) const {return sqrt(_real*_real+_imaginary*_imaginary);}
		const bool operator ==(const Complex& right) const {return absoluteValue() == right.absoluteValue();}
		const bool operator <(const Complex& right) const {return absoluteValue() < right.absoluteValue();}
		const bool operator <=(const Complex& right) const {return absoluteValue() <= right.absoluteValue();}
		const bool operator >(const Complex& right) const {return absoluteValue() > right.absoluteValue();}
		const bool operator >=(const Complex& right) const {return absoluteValue() >= right.absoluteValue();}
		const Complex operator +(const Complex& right) const {return Complex(_real+right._real,_imaginary+right._imaginary);}
		const Complex operator -(const Complex& right) const {return Complex(_real-right._real,_imaginary-right._imaginary);}
		const Complex operator *(const Complex& right) const {return Complex(_real*right._real-_imaginary*right._imaginary,_imaginary*right._real+_real*right._imaginary);}
		const Complex operator /(const Complex& right) const {return Complex((_real*right._real+_imaginary*right._imaginary)/(right._real*right._real+right._imaginary*right._imaginary),(_imaginary*right._real-_real*right._imaginary)/(right._real*right._real+right._imaginary*right._imaginary));}
	private:
		double _real,_imaginary;
};

void inputNumber(Complex& number1,Complex& number2)
{
	std::cout << "Write in first complex number: ";
	std::cin >> number1;
	std::cout << "Write in second complex number: ";
	std::cin >> number2;
}

int main(void)
{
	Complex number1,number2,number3;
	for (;;)
	{
		std::cout << "Calculate complex numbers.\nPress a for absolute value. Press q to quit.\nChoose operator: ";
		std::string operation;
		std::cin >> operation;
		if (operation == "a")
			std::cout << number3.absoluteValue() << std::endl;
		else if (operation == "==")
		{
			inputNumber(number1,number2);
			if (number1 == number2)
				std::cout << "True." << std::endl;
			else
				std::cout << "False." << std::endl;
		}
		else if (operation == "<")
		{
			inputNumber(number1,number2);
			if (number1 < number2)
				std::cout << "True." << std::endl;
			else
				std::cout << "False." << std::endl;
		}
		else if (operation == "<=")
		{
			inputNumber(number1,number2);
			if (number1 <= number2)
				std::cout << "True." << std::endl;
			else
				std::cout << "False." << std::endl;
		}
		else if (operation == ">")
		{
			inputNumber(number1,number2);
			if (number1 > number2)
				std::cout << "True." << std::endl;
			else
				std::cout << "False." << std::endl;
		}
		else if (operation == ">=")
		{
			inputNumber(number1,number2);
			if (number1 >= number2)
				std::cout << "True." << std::endl;
			else
				std::cout << "False." << std::endl;
		}
		else if (operation == "+")
		{
			inputNumber(number1,number2);
			number3 = number1 + number2;
			std::cout << number3 << std::endl;
		}
		else if (operation == "-")
		{
			inputNumber(number1,number2);
			number3 = number1 - number2;
			std::cout << number3 << std::endl;
		}
		else if (operation == "*")
		{
			inputNumber(number1,number2);
			number3 = number1 * number2;
			std::cout << number3 << std::endl;
		}
		else if (operation == "/")
		{
			inputNumber(number1,number2);
			number3 = number1 / number2;
			std::cout << number3 << std::endl;
		}
		else if (operation == "q")
			break;
		else
			std::cout << "Wrong input." << std::endl;
	}
	return 0;
}
