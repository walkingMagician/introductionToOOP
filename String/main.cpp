#include <iostream>
#include <cstring>
#include <string>
#include <windows.h>

using namespace std;

class String
{
private:
	string str;
public:

	 //set/get
	string get_str() { return str; }

	void set_str(string str) { this->str = str; }

	// constructor
	String()
	{
		this->str.resize(80);
		cout << "default constructor:" <<"\t\t" << this << endl;
	}

	String(const char* ch1)
	{
		set_str(ch1);
		cout << "char constructor:" << "\t\t" << this << endl;
	}

	String(const String& other)
	{
		this->str = other.str;
		cout << "Copy constructor:" <<"\t\t" << this << endl;
	}

	~String()
	{
		cout << "destructor:" << "\t\t" << this << endl;
	}

	// operators
	String& operator=(const String& other)
	{
		this->str = other.str;
		
		cout << "Copy Assighment:\t\t" << this << endl;
		return *this;
	}

	// methods
	std::ostream& print(std::ostream& os = std::cout) const
	{
		os << str << endl;
		return os;
	}
};

std::ostream& operator<<(std::ostream& os, const String& obj) 
{
	return obj.print(os);
}

String operator+(String left, String right) 
{
	String result;
	result.set_str(left.get_str() + right.get_str());
	return result;
}

void main()
{
	String A ="hello";
	//A.print();
	String B = "world";
	//B.print();
	String C = A + B;
	cout << C << endl;
	
	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;

}