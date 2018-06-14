#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#define NUMBERS_INT 10000

class OpenFileException : public std::runtime_error
{
	public:
		OpenFileException(void) : std::runtime_error("Can't open file!") {}
};

class ArithmeticSeries
{
	public:
		void generateFile(const std::string file = "integers.txt")
		{
			srand(time(NULL));
			_file = file;
			std::ofstream out(_file);
			if (out.fail())
				throw OpenFileException();
			for (int i = 0; i < NUMBERS_INT; i++)
				out << rand()%20 << " ";
			out.close();
		}
		void writeSerie(const std::string file = "artithmeticseries.txt") const
		{
			std::ifstream in(_file);
			if (in.fail())
				throw OpenFileException();
			std::ofstream out(file);
			if (out.fail())
				throw OpenFileException();
			int last;
			in >> last;
			while (!in.eof())
			{
				int number;
				in >> number;
				if (number - last == 4)
				{
					out << last << " ";
					if (in.peek() - number != 4)
						out << number << std::endl;
				}
				last = number;
			}
			in.close();
			out.close();
		}
	private:
		std::string _file;
};

int main(void)
{
	ArithmeticSeries art;
	try
	{
		art.generateFile();
	}
	catch(OpenFileException e)
	{
		std::cerr << "Tried to create the file." << std::endl;
		exit(1);
	}
	try
	{
		art.writeSerie();
	}
	catch(OpenFileException e)
	{
		std::cerr << "Tried to either create or open the files." << std::endl;
		exit(1);
	}
	std::cout << "Success." << std::endl;
	exit(0);
}
