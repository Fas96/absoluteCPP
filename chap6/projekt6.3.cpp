#include <iostream>

class Point
{
	public:
		Point(const double x = 0,const double y = 0) : _x(x),_y(y) {}
		void set(const double x,const double y) {_x = x; _y = y;}
		void move(const double dx,const double dy) {_x += dx; _y += dy;}
		void rotate(void)
		{
			double tmpX = _x;
			_x = _y*-1;
			_y = tmpX*-1;
		}
		const double getX(void) const {return _x;}
		const double getY(void) const {return _y;}
		friend std::istream& operator >>(std::istream& input,Point& point)
		{
			double x,y;
			std::cout << "X: ";
			input >> x;
			std::cout << "Y: ";
			input >> y;
			point.set(x,y);
			return input;
		}
		friend std::ostream& operator <<(std::ostream& output,const Point& point)
		{
			output << "X: " << point.getX() << "\nY: " << point.getY();
			return output;
		}
	private:
		double _x,_y;
};

int main(void)
{
	Point point;
	std::cin >> point;
	point.move(4.2,-2.1);
	std::cout << point << std::endl;
	point.rotate();
	std::cout << point << std::endl;
	return 0;
}
