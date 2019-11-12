#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::istringstream;
using std::ostringstream;
using std::stringstream;

void test0(void)
{
	int number1 = 10;
	int number2 = 20;
	stringstream ss;
	ss << "number1=" << number1 << " number2= " << number2;
	cout << ss.str() << endl;
	string word;
	int value;
	while( ss >> word >> value)
	{
		cout << word << value << endl;
	}
}

string inttostr(int number)
{
	ostringstream oss;
	oss << number;
	return oss.str();
}

void readConfiguration()
{
	ifstream ifs;
	ifs.open("a.txt");
	if(!ifs){
		cout << "ifstream open error!" << endl;
		return;
	}
	string line;
	string key;
	string value;
	while(getline(ifs,line))
	{
		istringstream iss(line);
		iss >> key >> value;
		cout << key << " -- >> " << value << endl;
	}
	ifs.close();
}


int main(void)
{
	test0();
	int number = 123;
	cout << inttostr(number) << endl;
	readConfiguration();
}
