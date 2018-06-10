#include <iostream>
#include <cmath>

class Circle
{
	public:
		Circle(const double r = 0) : _radius(r) {}
		void setRadius(const double r) {_radius = r;}
		const double getRadius(void) const {return _radius;}
		const double getArea(void) const {return _radius*_radius*M_PI;}
		const double getDiameter(void) const {return _radius*2;}
		const double getCircumference(void) const {return _radius*2*M_PI;}
	private:
		double _radius;
};

int main(void)
{
	Circle circle(8.9);
	std::cout << "Circle:\n" << "Radius: " << circle.getRadius() << "\nArea: " << circle.getArea() << "\nDiameter: " << circle.getDiameter() << "\nCircumference: " << circle.getCircumference() << std::endl;
	circle.setRadius(12.56);
	std::cout << "Circle:\n" << "Radius: " << circle.getRadius() << "\nArea: " << circle.getArea() << "\nDiameter: " << circle.getDiameter() << "\nCircumference: " << circle.getCircumference() << std::endl;
	return 0;
}
