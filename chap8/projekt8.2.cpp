#include <iostream>
#include <cstdlib>

class DivisionByZeroException : public std::runtime_error
{
	public:
		DivisionByZeroException(void) : std::runtime_error("Division by zero!") {}
};

class Rational
{
	public:
		Rational(const int numerator = 0, const int denominator = 1) : _numerator(numerator)
		{
			if (denominator == 0)
				throw DivisionByZeroException();
			else
				_denominator = denominator;
		}
		friend std::istream& operator >>(std::istream& input,Rational& rational)
		{
			int numerator,denominator;
			char divide;
			input >> numerator;
			input >> divide;
			input >> denominator;
			if (divide == '/')
			{
				if (denominator == 0)
					throw DivisionByZeroException();
				else
				{
					rational._numerator = numerator;
					rational._denominator = denominator;
				}
			}
			return input;
		}
		friend std::ostream& operator <<(std::ostream& output,const Rational& rational)
		{
			output << rational._numerator << "/" << rational._denominator << std::endl;
			return output;
		}
		const bool operator ==(const Rational& right) const {return _numerator*right._denominator == _denominator*right._numerator;}
		const bool operator <(const Rational& right) const {return _denominator < 0 || right._denominator < 0 ? _numerator*right._denominator*-1 < _denominator*right._numerator*-1 : _numerator*right._denominator < _denominator*right._numerator;}
		const bool operator <=(const Rational& right) const {return *this < right || *this == right;}
		const bool operator >(const Rational& right) const {return _denominator < 0 || right._denominator < 0 ? _numerator*right._denominator*-1 > _denominator*right._numerator*-1 : _numerator*right._denominator > _denominator*right._numerator;}
		const bool operator >=(const Rational& right) const {return *this > right || *this == right;}
		const Rational operator +(const Rational& right) const {return Rational(_numerator*right._denominator+_denominator*right._numerator,_denominator*right._denominator);}
		const Rational operator -(const Rational& right) const {return Rational(_numerator*right._denominator-_denominator*right._numerator,_denominator*right._denominator);}
		const Rational operator *(const Rational& right) const {return Rational(_numerator*right._numerator,_denominator*right._denominator);}
		const Rational operator /(const Rational& right) const
		{
			if (right._numerator == 0)
				throw DivisionByZeroException();
			else
				return Rational(_numerator*right._denominator,_denominator*right._numerator);
		}
		void normalization(void)
		{
			if (_denominator < 0)
			{
				_numerator *= -1;
				_denominator *= -1;
			}
			// This doesn't work, I don't know why, b gets the same value as a, this EXACT code works perfektly in projekt6.5
			int a,b;
			_numerator > _denominator ? a = _numerator,b = _denominator : a = _denominator,b = _numerator;
			while (b != 0)
			{
				int c = a % b;
				a = b;
				b = c;
			}
			_numerator /= a;
			_denominator /= a;
		}
	private:
		int _numerator,_denominator;
};

void inputNumber(Rational& number1,Rational& number2)
{
	for (;;)
	{
		std::cout << "Write a rational number: ";
		try
		{
			std::cin >> number1;
		}
		catch (DivisionByZeroException e)
		{
			std::cerr << "Can't divide by zero! Try again." << std::endl;
			continue;
		}
		break;
	}
	for (;;)
	{
		std::cout << "Write a second rational number: ";
		try
		{
			std::cin >> number2;
		}
		catch (DivisionByZeroException e)
		{
			std::cerr << "Can't divide by zero! Try again." << std::endl;
			continue;
		}
		break;
	}
}

int main(void)
{
	Rational number1,number2,number3;
	for (;;)
	{
		std::string operation;
		std::cout << "Rational calculator.\nTo quit type q, for normalizing the rational number type n.\nChoose an operator: ";
		std::cin >> operation;
		if (operation == "==")
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
		else if (operation == "n")
		{
			number3.normalization();
			std::cout << number3 << std::endl;
		}
		else if (operation == "q")
			break;
		else
			std::cerr << "Wrong input." << std::endl;
	}
	std::exit(0);
}
