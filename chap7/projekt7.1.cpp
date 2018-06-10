#include <iostream>
#include <cstring>

enum Color{BLACK,WHITE,RED,LIME,BLUE,YELLOW,CYAN,MAGENTA,SILVER,GRAY,MAROON,OLIVE,GREEN,PURPLE,TEAL,NAVY};

class RainbowColor
{
	public:
		RainbowColor(const std::string color = "BLACK")
		{
			if (color == "BLACK")
				_color = BLACK;
			else if (color == "WHITE")
				_color = WHITE;
			else if (color == "RED")
				_color = RED;
			else if (color == "LIME")
				_color = LIME;
			else if (color == "BLUE")
				_color = BLUE;
			else if (color == "YELLOW")
				_color = YELLOW;
			else if (color == "CYAN")
				_color = CYAN;
			else if (color == "MAGENTA")
				_color = MAGENTA;
			else if (color == "SILVER")
				_color = SILVER;
			else if (color == "GRAY")
				_color = GRAY;
			else  if (color == "MAROON")
				_color = MAROON;
			else if (color == "OLIVE")
				_color = OLIVE;
			else if (color == "GREEN")
				_color = GREEN;
			else if (color == "PURPLE")
				_color = PURPLE;
			else if (color == "TEAL")
				_color = TEAL;
			else if (color == "NAVY")
				_color = NAVY;
			else
				_color = BLACK;
		}
		RainbowColor(const int color = BLACK) : _color((Color)color) {}
		void setColor(const int color) {color >= 16 ? _color = BLACK : _color = (Color)color;}
		const int getIntColor(void) const {return _color;}
		const std::string getStringColor(void) const
		{
			switch(_color)
			{
				case BLACK:
					return "BLACK";
				case WHITE:
					return "WHITE";
				case RED:
					return "RED";
				case LIME:
					return "LIME";
				case BLUE:
					return "BLUE";
				case YELLOW:
					return "YELLOW";
				case CYAN:
					return "CYAN";
				case MAGENTA:
					return "MAGENTA";
				case SILVER:
					return "SILVER";
				case GRAY:
					return "GRAY";
				case MAROON:
					return "MAROON";
				case OLIVE:
					return "OLIVE";
				case GREEN:
					return "GREEN";
				case PURPLE:
					return "PURPLE";
				case TEAL:
					return "TEAL";
				case NAVY:
					return "NAVY";
				default:
					return "BLACK";
			}
		}
		const RainbowColor next(void) const {return RainbowColor(_color+1);}
	private:
		Color _color;
};

int main(void)
{
	RainbowColor rainbow("RED");
	std::cout << "Color: " << rainbow.getStringColor() << std::endl;
	RainbowColor rainbow2 = rainbow.next();
	std::cout << "Color: " << rainbow2.getIntColor() << std::endl;
	return 0;
}
