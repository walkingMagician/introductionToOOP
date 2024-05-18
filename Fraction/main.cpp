#include <iostream>
#include <cmath>
using namespace std;

class Fraction
{
	int integer;	// целое
	int numerator;	// числитель
	int denominator;// знаменатель

public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0) denominator = 1;
		this->denominator = denominator;
	}

	//	constructor
	Fraction()
	{
		integer = 0;
		numerator = 0;
		denominator = 1;
		cout << "Default Constructor:\t\t" << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		numerator = 0;
		denominator = 1;
		cout << "1arg Constructor:\t\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "Copy Construction:\t\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	// operators
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "Copy Assighment:\t\t" << this << endl;
		return *this;
	}

	Fraction& operator++ () // prefix increment
	{
		if(integer) integer++;
		if(numerator) numerator++;
		if (denominator) denominator++;
		return *this;
	}
	
	Fraction operator++ (int) // Postfix increment
	{
		Fraction old = *this;
		if(integer) integer++;
		if (numerator) numerator++;
		if (denominator) denominator++;
		return old;
	}

	Fraction& operator-- () // prefix decrement
	{
		if (integer) integer--;
		if (numerator) numerator--;
		if (denominator) denominator--;
		return *this;
	}

	Fraction operator-- (int) // Postfix decrement
	{
		Fraction old = *this;
		if (integer) integer--;
		if (numerator) numerator--;
		if (denominator) denominator--;
		return old;
	}

	// Methods

	int comparison()
	{
		return get_integer() * get_denominator() - get_denominator() + get_numerator();
	}

	void print() const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer) cout << ")";
		}
		else if (integer == 0) cout << 0;
		cout << endl;
	}
};

bool operator== (const Fraction& left, const Fraction& right) 
{
	return left.get_integer() == right.get_integer() && left.get_numerator() == right.get_numerator() && left.get_denominator() == right.get_denominator();
}

bool operator!= (const Fraction& left, const Fraction& right)
{
	return left.get_integer() != right.get_integer() || left.get_numerator() != right.get_numerator() || left.get_denominator() != right.get_denominator();
}

bool operator< (Fraction& left, Fraction& right) { return left.comparison() < right.comparison(); }
bool operator> (Fraction& left, Fraction& right) { return left.comparison() > right.comparison(); }
bool operator<= (Fraction& left, Fraction& right) { return left.comparison() <= right.comparison(); }
bool operator>= (Fraction& left, Fraction& right) { return left.comparison() >= right.comparison(); }

Fraction operator*(const Fraction& left, const Fraction& right)
{
	Fraction result;

	result.set_numerator((left.get_integer() * left.get_denominator() + left.get_numerator()) * (right.get_integer() * right.get_denominator() + right.get_numerator()));
	result.set_denominator(left.get_denominator() * right.get_denominator());

	return result;
}

Fraction operator/(const Fraction& left, const Fraction& right)
{
	Fraction result;
	
	result.set_numerator((left.get_integer() * left.get_denominator() + left.get_numerator()) * right.get_denominator());
	result.set_denominator((right.get_integer() * right.get_denominator() + right.get_numerator()) * left.get_denominator());

	return result;

	//return Fraction(left.get_numerator() * right.get_denominator(), left.get_denominator() * right.get_numerator());
}

Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction result;
	//result.set_integer(left.get_integer() + right.get_integer());
	//result.set_numerator(left.get_numerator() + right.get_numerator());
	//result.set_denominator(left.get_denominator() + right.get_denominator());
	
	if (left.get_denominator() == right.get_denominator())
	{
		result.set_numerator((left.get_integer() * left.get_denominator() + left.get_numerator()) + (right.get_integer() * right.get_denominator() + right.get_numerator()));
		result.set_denominator(left.get_denominator());
	}else {
		result.set_numerator((left.get_integer() * left.get_denominator() + left.get_numerator()) * right.get_denominator() + (right.get_integer() * right.get_denominator() + right.get_numerator()) * left.get_denominator());
		result.set_denominator(left.get_denominator() * right.get_denominator());
	}
	
	return result;
}

Fraction operator-(const Fraction& left, const Fraction& right) 
{
	Fraction result;
	
	if (left.get_denominator() == right.get_denominator())
	{
		result.set_denominator(left.get_denominator());
		result.set_numerator((left.get_integer() * left.get_denominator() + left.get_numerator()) - (right.get_integer() * right.get_denominator() + right.get_numerator()));
	}else {
		result.set_numerator((left.get_integer() * left.get_denominator() + left.get_numerator()) * right.get_denominator() - (right.get_integer() * right.get_denominator() + right.get_numerator()) * left.get_denominator());
		result.set_denominator(left.get_denominator() * right.get_denominator());
	}

	return result;
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	return os << obj.get_integer() << "(" << obj.get_numerator() << "/" << obj.get_denominator() << ")";
}

std::istream& operator>>(std::istream& is, Fraction& obj)
{
	int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return is;
}



//#define ONE_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef ONE_CHECK
	Fraction A; //default constructor
	A.print();

	Fraction B = 5;
	B.print();

	Fraction C(1, 2);
	C.print();

	Fraction D(2, 3, 4);
	D.print();

	Fraction E = D;
	E.print();

	Fraction F;
	F = E;
	F.print();
#endif

	Fraction A(4, 8);
	Fraction B(2, 5, 7);
	A.print();
	B.print();
	Fraction C = A <= B;
	C.print();
	Fraction F;
	cin >> F;
	F.print();

}