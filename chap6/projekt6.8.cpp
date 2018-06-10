#include <iostream>

class Money
{
	public:
		Money(const int dollar = 0,const int cent = 0) : _dollar(dollar),_cent(cent) {}
		void setDollar(const int dollar) {_dollar = dollar;}
		void setCent(const int cent) {_cent = cent;}
		const int getDollar(void) const {return _dollar;}
		const int getCent(void) const {return _cent;}
		const double amount(void) const {return (double)_dollar+(double)_cent*0.01;}
	private:
		int _dollar,_cent;
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
