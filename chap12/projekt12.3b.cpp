#include <iostream>
#include <fstream>
#include <cstdlib>

#define NUMBER_INT 10000

class OpenFileException : public std::runtime_error
{
	public:
		OpenFileException(void) : std::runtime_error("Can't open file!") {}
};

class Quartile
{
	public:
		void generateFile(const std::string file = "integers.txt")
		{
			_file = file;
			std::ofstream out(_file);
			if (out.fail())
				throw OpenFileException();
			for (int i = 0; i <= NUMBER_INT; i++)
				out << i << ' ';
			out.close();
		}
		friend std::ostream& operator <<(std::ostream& out,const Quartile quartile)
		{
			std::ifstream in(quartile._file);
			if (in.fail())
				throw OpenFileException();
			int number = 0;
			for (int i; !in.eof(); number++)
				in >> i;
			in.close();
			in.clear();
			in.open(quartile._file);
			if (in.fail())
				throw OpenFileException();
			// First quartile.
			in.ignore(number/4-1);
			int quartileInt;
			in >> quartileInt;
			if (number%4 == 0)
			{
				int quartile2Int;
				in >> quartile2Int;
				out << "First quartile: " << (double)(quartileInt+quartile2Int)/2 << std::endl;
			}
			else
				out << "First quartile: " << quartileInt << std::endl;
			in.close();
			in.clear();
			in.open(quartile._file);
			if (in.fail())
				throw OpenFileException();
			// Second quartile.
			in.ignore(number/2-1);
			in >> quartileInt;
			if (number%2 == 0)
			{
				int quartile2Int;
				in >> quartile2Int;
				out << "Second quartile: " << (double)(quartileInt+quartile2Int)/2 << std::endl;
			}
			else
				out << "Second quartile: " << quartileInt << std::endl;
			in.close();
			in.clear();
			in.open(quartile._file);
			if (in.fail())
				throw OpenFileException();
			// Third quartile.
			in.ignore(number/4*3-1);
			in >> quartileInt;
			if (number%4 == 0)
			{
				int quartile2Int;
				in >> quartile2Int;
				out << "Third quartile: " << (double)(quartileInt+quartile2Int)/2;
			}
			else
				out << "Third quartile: " << quartileInt;
			in.close();
			return out;
		}
	private:
		std::string _file;
};

int main(void)
{
	Quartile quartile;
	try
	{
		quartile.generateFile();
	}
	catch(OpenFileException e)
	{
		std::cerr << "Tried to create the file." << std::endl;
		exit(1);
	}
	try
	{
		std::cout << quartile << std::endl;
	}
	catch(OpenFileException e)
	{
		std::cerr << "Tried to open the file." << std::endl;
		exit(1);
	}
	exit(0);
}
