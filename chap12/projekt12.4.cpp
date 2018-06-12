#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define NUMBER_DOUBLES 100

class OpenFileException : public std::runtime_error
{
	public:
		OpenFileException(void) : std::runtime_error("Can't open file!") {}
};

class Average
{
	public:
		void generateFile(const std::string file = "doubles.txt")
		{
			srand(time(NULL));
			_file = file;
			std::ofstream out(_file);
			if (out.fail())
				throw OpenFileException();
			else
				for (int i = 0; i < NUMBER_DOUBLES; i++)
					out << doubleRand(0.32,1894.78) << ' ';
			out.close();
		}
		friend std::ostream& operator <<(std::ostream& output,const Average& average)
		{
			double sum = 0.0,number = 0;
			std::ifstream in(average._file);
			if (in.fail())
				throw OpenFileException();
			while (!in.eof())
			{
				double next;
				in >> next;
				if (next != ' ')
				{
					sum += next;
					number++;
				}
			}
			double averageNumber = sum/number;
			in.close();
			in.clear();
			in.open(average._file);
			if (in.fail())
				throw OpenFileException();
			while (!in.eof())
			{
				double next;
				in >> next;
				output << pow(next-averageNumber,2) << " ";
			}
			in.close();
			return output;
		}
	private:
		const double doubleRand(const double min,const double max) const {return min + ((double)rand()/RAND_MAX) * (max-min);}
		std::string _file;
};

int main(void)
{
	Average average;
	try
	{
		average.generateFile();
	}
	catch(OpenFileException e)
	{
		std::cerr << "Tried to create the file." << std::endl;
		exit(1);
	}
	try
	{
		std::cout << "Average numbers:\n" << average << std::endl;
	}
	catch(OpenFileException e)
	{
		std::cerr << "Tried to read from the file." << std::endl;
		exit(1);
	}
	exit(0);
}
