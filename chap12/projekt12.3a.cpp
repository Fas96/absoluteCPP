#include <iostream>
#include <fstream>
#include <cstdlib>

#define NUMBER_INT 10000

class OpenFileException : public std::runtime_error
{
	public:
		OpenFileException() : std::runtime_error("Can't open file!") {}
};

class Median
{
	public:
		void generateFile(const std::string file = "integers.txt")
		{
			_file = file;
			std::ofstream out;
			out.open(_file);
			if (out.fail())
				throw OpenFileException();
			else
				for (int i = 0; i <= NUMBER_INT; i++)
					out << i << ' ';
			out.close();
		}
		friend std::ostream& operator <<(std::ostream& output,const Median& median)
		{
			std::ifstream in;
			in.open(median._file);
			if (in.fail())
				throw OpenFileException();
			int number = 0,middle;
			for (int i; !in.eof(); number++)
				in >> i;
			in.close();
			in.clear();
			in.open(median._file);
			if (in.fail())
				throw OpenFileException();
			in.ignore(number/2-1);
			in >> middle;
			if (number%2 == 0)
			{
				int middle2;
				in >> middle2;
				output << (double)(middle+middle2)/2;
			}
			else
				output << middle;
			in.close();
			return output;
		}
	private:
		std::string _file;
};

int main(void)
{
	Median median;
	try
	{
		median.generateFile();
	}
	catch(OpenFileException e)
	{
		std::cerr << "Tried to create the file." << std::endl;
		exit(1);
	}
	try
	{
		std::cout << "Median: " << median << std::endl;
	}
	catch(OpenFileException e)
	{
		std::cerr << "Tried to open the file." << std::endl;
		exit(1);
	}
	exit(0);
}
