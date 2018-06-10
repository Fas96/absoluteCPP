#include <iostream>

class Rectangle
{
	public:
		Rectangle(const double width = 5,const double height = 5) : _width(width),_height(height) {}
		void width(const double width) {_width = width;}
		const double width(void) const {return _width;}
		void height(const double height) {_height = height;}
		const double height(void) const {return _height;}
		const double area(void) const {return _width*_height;}
	private:
		double _width,_height;
};

int main(void)
{
	Rectangle rect;
	std::cout << "Rectangle:\n" << "Width: " << rect.width() << "\nHeight: " << rect.height() << "\nArea: " << rect.area() << std::endl;
	rect.width(7);
	rect.height(8);
	std::cout << "Rectangle:\n" << "Width: " << rect.width() << "\nHeight: " << rect.height() << "\nArea: " << rect.area() << std::endl;
	return 0;
}
