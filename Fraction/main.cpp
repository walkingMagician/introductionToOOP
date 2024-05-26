#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction& left, Fraction& right);
Fraction operator/(Fraction& left, Fraction& right);
Fraction operator+(Fraction& left, Fraction& right);
Fraction operator-(Fraction& left, Fraction& right);

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
	explicit Fraction(int integer)
	{
		this->integer = integer;
		numerator = 0;
		denominator = 1;
		cout << "1arg Constructor:\t\t" << this << endl;
	}

	Fraction(double decimal)
	{
		decimal += 1e-10;
		integer = decimal; // сохраняем целую часть 
		denominator = 1e+9; // 'int' позволяет полноценно использовать только 9 десятичных разрядов
		decimal -= integer; // убираем целую часть для целой части 
		numerator = decimal * denominator; 
		reduce();

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

	Fraction operator*=( Fraction& other)
	{
		return *this = *this * other;
	}

	Fraction operator/=( Fraction& other)
	{
		return *this = *this / other;
	}
	Fraction operator+=(Fraction& other)
	{
		return *this = *this + other;
	}
	Fraction operator-=(Fraction& other)
	{
		return *this = *this - other;
	}

	// type-cast operators 
	explicit operator int()
	{
		return integer;
	}

	operator double()
	{
		return integer + (double)numerator / denominator;
	}

	// Methods
	
	Fraction& to_proper() // перевод неправильную дробь в смешанную
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}

	void to_improper() // перевод смешанную дробь в неправильную
	{
		numerator += integer * denominator;
		integer = 0;
	}

	Fraction invertion() const // переворот дроби 
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}

	Fraction& reduce() // алгоритм евклида для сокращения дробейма
	{
		int more, less, rest;
		if (numerator > denominator) more = numerator, less = denominator;
		else less = numerator, more = denominator;

		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);;
		int GCD = more;	//Greatest Common Divisor
		numerator /= GCD;
		denominator /= GCD;
		return *this;
	}

	std::ostream& print(std::ostream& os = std::cout) const
	{
		if (integer)os << integer;
		if (numerator)
		{
			if (integer)os << "(";
			os << numerator << "/" << denominator;
			if (integer) os << ")";
		}
		else if (integer == 0) os << 0;
		os << endl;
		return os;
	}
};

bool operator== (const Fraction& left, const Fraction& right) // равны
{
	return left.get_integer() == right.get_integer() && left.get_numerator() == right.get_numerator() && left.get_denominator() == right.get_denominator();
}

bool operator!= (const Fraction& left, const Fraction& right) // не равны
{
	return left.get_integer() != right.get_integer() || left.get_numerator() != right.get_numerator() || left.get_denominator() != right.get_denominator();
}

bool operator>(Fraction left, Fraction right) // больше
{
	left.to_improper();
	right.to_improper();

	return left.get_numerator() * right.get_denominator() > left.get_denominator() * right.get_numerator();
}

bool operator<(Fraction left, Fraction right) // меньше
{
	left.to_improper();
	right.to_improper();
	
	return left.get_numerator() * right.get_denominator() < right.get_numerator() * left.get_denominator();
}

bool operator>=(const Fraction& left, const Fraction& right) // больше или равно
{
	//return left > right || left == right;
	return !(left < right);
}

bool operator<=(const Fraction& left, const Fraction& right) // меньше или равно
{
	return !(left > right);
}

Fraction operator*(Fraction& left, Fraction& right) // умножение
{
	left.to_improper();
	right.to_improper();

	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

Fraction operator/(Fraction& left, Fraction& right) // деление
{
	left.to_improper();
	right.to_improper();

	return Fraction
	(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	).to_proper().reduce();
}

Fraction operator+(Fraction& left,Fraction& right) // сложение
{
	left.to_improper();
	right.to_improper();

	return Fraction
	(
		left.get_numerator() * right.get_denominator() + right.get_denominator() * left.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();

}

Fraction operator-(Fraction& left,Fraction&right) // разность 
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_denominator() - right.get_denominator() * left.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}

std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	return obj.print(os);
}

std::istream& operator>>(std::istream& is, Fraction& obj)
{
	const int SIZE = 256;
	char buffer[SIZE]{};
	cin >> buffer;
	int n = 0;
	int numbers[3];
	char delimetr[] = "(/ )";
	for (char* pch = strtok(buffer, delimetr); pch; pch = strtok(NULL, delimetr))
		numbers[n++] = std::atoi(pch);
	//for (int i = 0; i < n; i++) cout << numbers[i] << "\t"; cout << endl;
	

	switch (n)
	{
	case 1: obj.set_integer(numbers[0]); break;
	case 2: 
		obj.set_numerator(numbers[0]); 
		obj.set_denominator(numbers[1]);
		break;
	case 3: 
		obj.set_integer(numbers[0]);
		obj.set_numerator(numbers[1]);
		obj.set_denominator(numbers[2]);
		break;
	}

	return is;
}

//#define ONE_CHECK
//#define TWO_CHECK
#define HOME_WORK

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

#ifdef TWO_CHECK
	Fraction A(2, 5);
	Fraction B(2, 5, 9);
	A.print();
	B.print();
	A += B;
	cout << A;
#endif

#ifdef HOME_WORK
	cout << INT_MIN << "..." << INT_MAX << endl;
	Fraction A(2, 3, 4);
	double a = A;
	cout << A << " = " << a << endl;

	Fraction B = 2.76;
	cout << B << endl;
#endif // HOME_WORK

}