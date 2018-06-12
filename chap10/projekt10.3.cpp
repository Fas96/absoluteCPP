#include <iostream>

const bool isWordCountBothEnds(std::string text)
{
	int beginCount = 0,endCount = 0;
	for (std::string::iterator beginIt = text.begin(),endIt = text.end()-1; beginIt < text.end() && endIt >= text.begin(); beginIt++,endIt--)
	{
		if (std::isspace(*beginIt))
			beginCount++;
		if (std::isspace(*endIt))
			endCount++;
	}
	return beginCount == endCount;
}

int main(void)
{
	std::string text;
	std::cin >> text;
	if (isWordCountBothEnds(text))
		std::cout << "True." << std::endl;
	else
		std::cout << "False." << std::endl;
	return 0;
}
