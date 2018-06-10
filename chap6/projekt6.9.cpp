#include <iostream>

class Money
{
	public:
		Money(const int dollar = 0,const int cent = 0) {_money = (double)dollar+(double)cent*0.01;}
		void setDollar(const int dollar) {_money = (_money - (int)_money) + dollar;}
		void setCent(const int cent) {_money = (int)_money + cent*0.01;}
		const int getDollar(void) const {return (int)_money;}
		const int getCent(void) const {return (_money-(int)_money)*100+1;}
		const double amount(void) const {return _money;}
	private:
		double _money;
};

int main(void)
{
	Money money(67,32);
	std::cout << "Dollar: " << money.getDollar() << "\nCent: " << money.getCent() << "\nAmount: " << money.amount() << std::endl;
	money.setDollar(43);
	money.setCent(22);
	std::cout << "Dollar: " << money.getDollar() << "\nCent: " << money.getCent() << "\nAmount: " << money.amount() << std::endl;
	return 0;
}
