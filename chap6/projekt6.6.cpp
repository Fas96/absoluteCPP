/*
 * I'm from Sweden, and in sweden a mile is 10 kilometers, thats why I have choosen to calculate in km/h instead of miles/h.
 */

#include <iostream>

class BicycleSpeedometer
{
	public:
		BicycleSpeedometer(const double km = 0,const double min = 0) : _km(km),_min(min) {}
		void setDistance(const double km) {_km = km;}
		void setTime(const double min) {_min = min;}
		const double getDistance(void) const {return _km;}
		const double getTime(void) const {return _min;}
		friend std::istream& operator >>(std::istream& input,BicycleSpeedometer& bS)
		{
			double km,min;
			std::cout << "Kilometers: ";
			input >> km;
			bS.setDistance(km);
			std::cout << "Time in minutes: ";
			input >> min;
			bS.setTime(min);
			return input;
		}
		const double averageSpeed(void) const {return _km/(_min/60);}
	private:
		double _km,_min;
};

int main(void)
{
	BicycleSpeedometer bS;
	std::cin >> bS;
	std::cout << "Average speed: " << bS.averageSpeed() << " km/h" << std::endl;
	return 0;
}
