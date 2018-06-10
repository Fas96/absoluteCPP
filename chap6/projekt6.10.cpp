#include <iostream>

#define KILO 2.2046
#define OUNCE 16

class Weight
{
	public:
		Weight(const double pounds = 0) : _pounds(pounds) {}
		void setWeightPounds(const double pounds) {_pounds = pounds;}
		void setWeightKilograms(const double kilograms) {_pounds = kilograms * KILO;}
		void setWeightOunces(const double ounces) {_pounds = ounces / OUNCE;}
		const double getWeightPounds(void) const {return _pounds;}
		const double getWeightKilograms(void) const {return _pounds / KILO;}
		const double getWeightOunces(void) const {return _pounds * OUNCE;}
	private:
		double _pounds;
};

int main(void)
{
	Weight weight(5);
	std::cout << weight.getWeightPounds() << " pounds = " << weight.getWeightKilograms() << " kilograms.\n" << weight.getWeightPounds() << " pounds = " << weight.getWeightOunces() << " ounces." << std::endl;
	return 0;
}
