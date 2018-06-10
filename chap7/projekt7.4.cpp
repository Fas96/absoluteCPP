#include <iostream>

class HotDogStand
{
	public:
		HotDogStand(const int id = 0,const int sold = 0) : _id(id),_sold(sold) {}
		void justSold(void) {_sold++; _allSold++;}
		const int numberSold(void) const {return _sold;}
		static const int allNumberSold(void) {return _allSold;}
	private:
		int _id,_sold;
		static int _allSold;
};

int HotDogStand::_allSold = 0;

int main(void)
{
	HotDogStand one,two(1),three(2);
	for (int i = 0; i < 10; i++)
		one.justSold();
	for (int i = 0; i < 23; i++)
		two.justSold();
	for (int i = 0; i < 34; i++)
		three.justSold();
	std::cout << "One: " << one.numberSold() << "\nTwo: " << two.numberSold() << "\nThree: " << three.numberSold() << "\nAll: " << HotDogStand::allNumberSold() << std::endl;
	return 0;
}
