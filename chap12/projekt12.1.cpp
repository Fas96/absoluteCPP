#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

#define INT_NUMBERS 10000

class OpenFileException : public std::runtime_error
{
	public:
		OpenFileException(void) : std::runtime_error("Can't open file!") {}
};

class SearchPrimeNumbers
{
	public:
		void createIntegers(std::string file = "integers.txt")
		{
			_file = file;
			std::ofstream out;
			out.open(_file);
			if (out.fail())
				throw OpenFileException();
			else
				for (int i = 0; i < INT_NUMBERS; i++)
					out << i << ' ';
			out.close();
		}
		friend std::ostream& operator <<(std::ostream& output,const SearchPrimeNumbers& prime)
		{
			std::ifstream in;
			in.open(prime._file);
			if (in.fail())
				throw OpenFileException();
			else
				while (!in.eof())
				{
					int next;
					in >> next;
					if (next != ' ' && prime.isPrime(next))
						output << next << " ";
				}
			in.close();
			return output;
		}
	private:
		const bool isPrime(const int number) const
		{
			if (number == 0 || number == 1)
				return false;
			for (int i = 2; i <= sqrt(number); i++)
				if (number % i == 0)
					return false;
			return true;
		}
		std::string _file;
};

int main(void)
{
	SearchPrimeNumbers prime;
	try
	{
		prime.createIntegers();
	}
	catch (OpenFileException e)
	{
		std::cerr << "Tried to create the file." << std::endl;
		exit(1);
	}
	try
	{
		std::cout << prime << std::endl;
	}
	catch (OpenFileException e)
	{
		std::cerr << "Tried to read from the file." << std::endl;
		exit(1);
	}
	exit(0);
}
