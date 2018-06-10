#include <iostream>
#include <cmath>

class PrimeNumber
{
	public:
		PrimeNumber(const int number = 2)
		{
			if (isPrime(number))
				_prime = number;
		}
		const int get(void) const {return _prime;}
		const PrimeNumber operator ++(void) // Prefix
		{
			while (!isPrime(++_prime));
			return PrimeNumber(_prime);
		}
		const PrimeNumber operator ++(int ignoreMe) // Postfix
		{
			PrimeNumber tmp = _prime;
			while (!isPrime(++_prime));
			return PrimeNumber(tmp);
		}
		const PrimeNumber operator --(void) // Prefix
		{
			while (!isPrime(--_prime));
			return PrimeNumber(_prime);
		}
		const PrimeNumber operator --(int ignoreMe) // Postfix
		{
			PrimeNumber tmp = _prime;
			while (!isPrime(--_prime));
			return PrimeNumber(tmp);
		}
	private:
		const bool isPrime(const int number) const
		{
			for (int i = 2; i <= (int)sqrt((double)number); i++)
				if (number % i == 0)
					return false;
			return true;
		}
		int _prime;
};

int main(void)
{
	PrimeNumber prime;
	std::cout << "The first 100 prime numbers from lowest to highest:" << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << prime++.get() << " ";
	std::cout << "\nThe first 100 prime numbers from highest to lowest:" << std::endl;
	for (int i = 0; i < 100; i++)
		std::cout << prime--.get() << " ";
	std::cout << std::endl;
	return 0;
}
