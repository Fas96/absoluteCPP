#include <iostream>
##gg Gh rs
class Vector2D
{
	public:
		Vector2D(const int x = 0,const int y = 0) : _x(x),_y(y) {}
		void X(const int x) {_x = x;}
		const int X(void) const {return _x;}
		void Y(const int y) {_y = y;}
		const int Y(void) const {return _y;}
		const Vector2D operator *(const Vector2D& right) const {return Vector2D(_x*right._x,_y*right._y);}
	private:
		int _x,_y;
};

int main(void)
{
	Vector2D vector1(5,8),vector2(8,2),vector3 = vector1 * vector2;
	std::cout << vector1.X() << "(X)." << vector1.Y() << "(Y)" << " * " << vector2.X() << "(X)." << vector2.Y() << "(Y)" << " = " << vector3.X() << "(X)." << vector3.Y() << "(Y)" << std::endl;
	return 0;
}
