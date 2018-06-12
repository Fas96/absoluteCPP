#include <iostream>
#include <vector>

class Television
{
	public:
		Television(const std::string displayType = "",const double dimension = 0,const std::string *connectivitySupport = nullptr,const int modes = 0) : _displayType(displayType),_dimension(dimension),_modes(modes)
		{
			if (connectivitySupport == nullptr)
				_connectivitySupport = nullptr;
			else
			{
				_connectivitySupport = new std::string[modes];
				for (int i = 0; i < modes; i++)
					_connectivitySupport[i] = connectivitySupport[i];
			}
		}
		Television(const Television& television) : _displayType(television._displayType),_dimension(television._dimension),_modes(television._modes)
		{
			if (television._connectivitySupport == nullptr)
				_connectivitySupport = television._connectivitySupport;
			else
			{
				_connectivitySupport = new std::string[_modes];
				for (int i = 0; i < _modes; i++)
					_connectivitySupport[i] = television._connectivitySupport[i];
			}
		}
		const std::string getDisplayType(void) const {return _displayType;}
		void setDisplayType(const std::string displayType) {_displayType = displayType;}
		const double getDimension(void) const {return _dimension;}
		void setDimension(const double dimension) {_dimension = dimension;}
		const int getModes(void) const {return _modes;}
		const std::string getConnectivitySupport(const int index) const {return _connectivitySupport[index];}
		void setConnectivitySupport(const std::string *connectivitySupport,const int modes)
		{
			if (_connectivitySupport != nullptr)
				delete [] _connectivitySupport;
			if (connectivitySupport == nullptr)
				_connectivitySupport = nullptr;
			else
			{
				_connectivitySupport = new std::string[modes];
				for (int i = 0; i < modes; i++)
					_connectivitySupport[i] = connectivitySupport[i];
			}
			_modes = modes;
		}
		void addConnectivitySupport(const std::string connectivitySupport)
		{
			std::string *tmp = _connectivitySupport;
			_connectivitySupport = new std::string[_modes+1];
			if (tmp != nullptr)
				for (int i = 0; i < _modes; i++)
					_connectivitySupport[i] = tmp[i];
			_connectivitySupport[_modes] = connectivitySupport;
			_modes++;
		}
		void clearConnectivitySupport(void)
		{
			if (_connectivitySupport != nullptr)
				delete [] _connectivitySupport;
		}
		~Television(void)
		{
			if (_connectivitySupport != nullptr)
				delete [] _connectivitySupport;
		}
	private:
		std::string _displayType;
		double _dimension;
		int _modes;
		std::string *_connectivitySupport;
};

int main(void)
{
	std::vector<Television> tvVector;
	std::string displayType,connectivitySupport;
	double dimension;
	int modes;
	std::cout << "Specifie the television:\nDisplay type: ";
	std::cin >> displayType;
	std::cout << "Dimension: ";
	std::cin >> dimension;
	std::cout << "Connectivity Support Modes: ";
	std::cin >> modes;
	Television tv1(displayType,dimension);
	for (int i = 0; i < modes; i++)
	{
		std::cout << "Connectivity Support: ";
		std::cin >> connectivitySupport;
		tv1.addConnectivitySupport(connectivitySupport);
	}
	tvVector.push_back(tv1);
	for (;;)
	{
		std::string answer;
		std::cout << "Add new television: ";
		std::cin >> answer;
		if (answer == "no" || answer == "No" || answer == "NO" || answer == "nO")
			break;
		else if (answer == "yes" || answer == "Yes" || answer == "YES" || answer == "yEs" || answer == "yeS" || answer == "YeS" || answer == "YEs" || answer == "yES")
		{
			Television tv(tv1);
			tvVector.push_back(tv);
			for (;;)
			{
				std::cout << "Change any values: ";
				std::cin >> answer;
				if (answer == "no" || answer == "No" || answer == "NO" || answer == "nO")
					break;
				else if (answer == "yes" || answer == "Yes" || answer == "YES" || answer == "yEs" || answer == "yeS" || answer == "YeS" || answer == "YEs" || answer == "yES")
				{
					std::cout << "Display type: ";
					std::cin >> displayType;
					std::cout << "Dimension: ";
					std::cin >> dimension;
					std::cout << "Connectivity Support Modes: ";
					std::cin >> modes;
					tvVector.back().clearConnectivitySupport();
					tvVector.back().setDisplayType(displayType);
					tvVector.back().setDimension(dimension);
					for (int i = 0; i < modes; i++)
					{
						std::cout << "Connectivity Support: ";
						std::cin >> connectivitySupport;
						tvVector.back().addConnectivitySupport(connectivitySupport);
					}
				}
				else
				{
					std::cerr << "Wrong input." << std::endl;
					continue;
				}
			}
		}
		else
		{
			std::cerr << "Wrong input." << std::endl;
			continue;
		}
	}
	while (!tvVector.empty())
	{
		std::cout << "Television:\n" << "Display type: " << tvVector.back().getDisplayType() << "\nDimension: " << tvVector.back().getDimension() << std::endl;
		for (int i = 0; i < tvVector.back().getModes(); i++)
			std::cout << "Connectivity Support: " << tvVector.back().getConnectivitySupport(i) << std::endl;
		tvVector.pop_back();
	}
	return 0;
}
