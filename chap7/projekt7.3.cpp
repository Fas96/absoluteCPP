#include <iostream>

class Counter
{
	public:
		Counter(const int max = 9999) : _max(max),_counter(0) {}
		void reset(void) {_counter = 0;}
		void incr1(const int inc) {_counter += 1*inc;}
		void incr10(const int inc) {_counter += 10*inc;}
		void incr100(const int inc) {_counter += 100*inc;}
		void incr1000(const int inc) {_counter += 1000*inc;}
		const bool overflow(void) const {return _counter > _max;}
		const int getCounter(void) const {return _counter;}
	private:
		int _max,_counter;
};

int main(void)
{
	Counter counter;
	char tecken;
	int amount;
	for (;;)
	{
		std::cout << "a = cents, s = dimes, d = dollars, f = tens of dollars, o = overflow, r = reset, q = quit." << std::endl;
		std::cin >> tecken;
		if (tecken == 'o')
		{
			if (counter.overflow())
			{
				std::cout << "The counter has flooded." << std::endl;
				break;
			}
			else
				std::cout << "The counter is inside the parameters. Counter: " << counter.getCounter() << std::endl;
		}
		else if (tecken == 'r')
			counter.reset();
		else if (tecken == 'q')
			break;
		else
		{
			std::cout << "1 - 9" << std::endl;
			std::cin >> amount;
			if (amount <= 9 || amount >= 0)
				switch(tecken)
				{
					case 'a':
						counter.incr1(amount);
						break;
					case 's':
						counter.incr10(amount);
						break;
					case 'd':
						counter.incr100(amount);
						break;
					case 'f':
						counter.incr1000(amount);
						break;
					default:
						std::cout << "Wrong input." << std::endl;
						break;
				}
			else
				std::cout << "Wrong input." << std::endl;
		}
		if (counter.overflow())
		{
			std::cout << "The counter has flooded." << std::endl;
			break;
		}
		else
			std::cout << "The counter is inside the parameters. Counter: " << counter.getCounter() << std::endl;
	}
	return 0;
}
