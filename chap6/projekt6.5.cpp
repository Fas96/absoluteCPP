#include <iostream>

class Fraction
{
	public:
		Fraction(const int numerator = 0,const int denominator = 1) : _numerator(numerator)
		{
			if (denominator == 0)
			{
				std::cout << "Can't divid by zero! Setting denominator to default value." << std::endl;
				_denominator = 1;
			}
			else
				_denominator = denominator;
		}
		void setNumerator(const int numerator) {_numerator = numerator;}
		void setDenominator(const int denominator)
		{
			if (denominator == 0)
				std::cout << "Can't divid by zero!" << std::endl;
			else
				_denominator = denominator;
		}
		const int getNumerator(void) const {return _numerator;}
		const int getDenominator(void) const {return _denominator;}
		const double floatnumber(void) const {return (double)_numerator/(double)_denominator;}
		void lowestTerms(void)
		{
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
		friend std::istream& operator >>(std::istream& input,Fraction& fraction)
		{
			int n;
			input >> n;
			fraction.setNumerator(n);
			char div;
			input >> div;
			if (div != '/')
			{
				std::cout << "Not a fraction! Setting denominator to default value." << std::endl;
				n = 1;
			}
			else
				input >> n;
			fraction.setDenominator(n);
			return input;
		}
		friend std::ostream& operator <<(std::ostream& output,const Fraction& fraction)
		{
			output << fraction.getNumerator() << "/" << fraction.getDenominator();
			return output;
		}
	private:
		int _numerator,_denominator;

};

int main(void)
{
	std::cout << "Input fraction: ";
	Fraction fraction;
	std::cin >> fraction;
	std::cout << "Fraction: " << fraction << "\nFloat: " << fraction.floatnumber() << std::endl;
	fraction.lowestTerms();
	std::cout << "Lowest terms: " << fraction << std::endl;
	return 0;
}
