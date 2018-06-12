#include <iostream>

class Subscriber
{
	public:
		Subscriber(std::string name = "",std::string *channelList = nullptr,int numChannels = 0) : _name(name),_numChannels(0),_size(0),_channelList(nullptr) {add(channelList,numChannels);}
		Subscriber(const Subscriber& subscriber) : _name(subscriber._name),_numChannels(subscriber._numChannels),_size(subscriber._size),_channelList(nullptr)
		{
			_channelList = new std::string[_size];
			if (subscriber._channelList != nullptr)
				for (int i = 0; i < _numChannels; i++)
					_channelList[i] = subscriber._channelList[i];
		}
		void input(std::string name,std::string *channelList,int numChannels)
		{
			if (name != "")
				_name = name;
			if (channelList != nullptr)
				add(channelList,numChannels);
		}
		friend std::ostream& operator <<(std::ostream& output,const Subscriber& subscriber)
		{
			output << "Subscriber: " << subscriber._name << "\nNumber of subscriptions: " << subscriber._numChannels << std::endl;
			if (subscriber._channelList != nullptr)
				for (int i = 0; i < subscriber._numChannels; i++)
					output << subscriber._channelList[i] << std::endl;
			return output;
		}
		void reset(void)
		{
			_size = _numChannels = 0;
			if (_channelList != nullptr)
			{
				delete [] _channelList;
				_channelList = nullptr;
			}
		}
		Subscriber& operator =(const Subscriber& right)
		{
			if (this != &right)
			{
				_name = right._name;
				_size = right._size;
				_numChannels = right._numChannels;
				if (_channelList != nullptr)
					delete [] _channelList;
				_channelList = new std::string[_size];
				if (right._channelList != nullptr)
					for (int i = 0; i < _numChannels; i++)
						_channelList[i] = right._channelList[i];
			}
			return *this;
		}
		~Subscriber(void)
		{
			if (_channelList != nullptr)
				delete [] _channelList;
		}
	private:
		void add(std::string *channelList,int numChannels)
		{
			if (channelList != nullptr)
			{
				for (int i = _numChannels,j = 0; i < _numChannels+numChannels && j < numChannels; i++,j++)
				{
					if (_size <= i)
					{
						int newSize = _size*2+1;
						std::string *tmp = _channelList;
						_channelList = new std::string[newSize];
						if (tmp != nullptr)
						{
							for (int k = 0; k < _size; k++)
								_channelList[k] = tmp[k];
							delete [] tmp;
						}
						_size = newSize;
					}
					_channelList[i] = channelList[j];
				}
				_numChannels += numChannels;
			}
		}
		std::string _name;
		int _numChannels,_size;
		std::string *_channelList;
};

int main(void)
{
	std::string channels[] = {"CaseyNeistat","colinfurze","Computerphile","Dan Mace","danscourses","DeepLearning.TV","Derek Banas","Dude Perfekt","ERB","ExplosmEntertainment","Freudian Slip Productions","H3 Podcast","iJustine","IJustWantToBeCool","IJustWantToBeCool2","It's Okay To Be Smart","JLC","KassHumor","Kurzgesagt - In a Nutshell","LEMMiNO","Linus Tech Tips","Marques Brownlee","NordicHardware","Numberphile","PewDiePie","sentdex","Simone Giertz","Sorelle Amore","Spinnin' Records","Strange Parts","SweClockers","SweClockers extrakanal","TechLinked","Techquickie","Tested","The Film Theorists","The Game Theorists","Vsauce","Vsauce2","Vsauce3"},addChannels[] = {"IGN","FBE","Team Coco"};
	Subscriber sub1("Andreas",channels,40);
	Subscriber sub2 = sub1;
	sub1.input("",addChannels,3);
	Subscriber sub3(sub1);
	sub1.reset();
	std::cout << "Sub1:\n" << sub1 << "Sub2:\n" << sub2 << "Sub3:\n" << sub3 << std::endl;
	return 0;
}
