#include <iostream>

class DynamicStringArray
{
	public:
		DynamicStringArray(const std::string *dynamicArray = nullptr,const int number = 0) : _dynamicArray(nullptr),_number(0),_size(0) {add(dynamicArray,number);}
		DynamicStringArray(const DynamicStringArray& dsa) : _dynamicArray(nullptr),_number(dsa._number),_size(dsa._size)
		{
			if (_dynamicArray != nullptr)
				delete [] _dynamicArray;
			_dynamicArray = new std::string[_size];
			for (int i = 0; i < _number; i++)
				_dynamicArray[i] = dsa._dynamicArray[i];
		}
		const int getSize(void) const {return _number;}
		void addEntry(const std::string newEntry) {add(&newEntry,1);}
		const bool deleteEntry(const std::string removeEntry)
		{
			for (int i = 0; i < _number; i++)
				if (removeEntry == _dynamicArray[i])
				{
					for (int j = i; j < _number; j++)
						if (!(j+1 == _number))
							_dynamicArray[j] = _dynamicArray[j+1];
					_number--;
					std::string *tmp = _dynamicArray;
					_dynamicArray = new std::string[_number];
					for (int j = 0; j < _number; j++)
						_dynamicArray[j] = tmp[j];
					delete [] tmp;
					_size = _number;
					return true;
				}
			return false;
		}
		const std::string getEntry(const int entry) const
		{
			if (entry < 0 || entry > _number)
				return nullptr;
			return _dynamicArray[entry];
		}
		const DynamicStringArray& operator =(const DynamicStringArray& right)
		{
			if (this != &right)
			{
				_number = right._number;
				_size = right._size;
				if (_dynamicArray != nullptr)
					delete [] _dynamicArray;
				_dynamicArray = new std::string[_size];
				if (right._dynamicArray != nullptr)
					for (int i = 0; i < _number; i++)
						_dynamicArray[i] = right._dynamicArray[i];
			}
			return *this;
		}
		~DynamicStringArray(void)
		{
			if (_dynamicArray != nullptr)
				delete [] _dynamicArray;
		}
	private:
		void add(const std::string *dynamicArray,const int number)
		{
			if (dynamicArray != nullptr)
			{
				for (int i = _number,j = 0; i < _number+number && j < number; i++,j++)
				{
					if (_size <= i)
					{
						int newSize = _size*2+1;
						std::string *tmp = _dynamicArray;
						_dynamicArray = new std::string[newSize];
						if (tmp != nullptr)
						{
							for (int k = 0; k < _size; k++)
								_dynamicArray[k] = tmp[k];
							delete [] tmp;
						}
						_size = newSize;
					}
					_dynamicArray[i] = dynamicArray[j];
				}
				_number += number;
			}
		}
		std::string *_dynamicArray;
		int _number,_size;
};

int main(void)
{
	std::string start[] = {"Hej","Hur","Har","Du","Det"},add[] = {"Vad","Gor","Andreas"};
	DynamicStringArray array1(start,5),array2(array1);
	for (int i = 0; i < 3; i++)
		array1.addEntry(add[i]);
	DynamicStringArray array3 = array1;
	if (!array3.deleteEntry("Hej"))
		std::cerr << "Could not find the string." << std::endl;
	if (!array3.deleteEntry("Har"))
		std::cerr << "Could not find the string." << std::endl;
	if (!array3.deleteEntry("Fel"))
		std::cerr << "Could not find the string." << std::endl;
	std::cout << "Array1:" << std::endl;
	for (int i = 0; i < array1.getSize(); i++)
		std::cout << array1.getEntry(i) << std::endl;
	std::cout << "Array2:" << std::endl;
	for (int i = 0; i < array2.getSize(); i++)
		std::cout << array2.getEntry(i) << std::endl;
	std::cout << "Array3:" << std::endl;
	for (int i = 0; i < array3.getSize(); i++)
		std::cout << array3.getEntry(i) << std::endl;
	return 0;
}
