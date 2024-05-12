#include <iostream>

using std::cout;
using namespace std;

class Point
{
	double x;
	double y;
public:
	
	double get_x()
	{
		return x;
	}
	double get_y()
	{
		return y;
	}

	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	// construction
	
	/*Point()
	{
		x = y = 0;
		cout << "constructors:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "single argument constructor: " << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "second argument constructor: " << this << endl;
	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "copy constructors:\t" << this << endl;
	}

	~Point()
	{
		cout << "destructor:\t" << this << endl;
	}
	// operator 

	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "copy assigmen:\t" << this << endl;
		return *this;
	}

	Point& operator++() // prefix increment
	{
		x++;
		y++;
		return *this;
	}

	Point operator++(int) // suffix increment
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}

	Point& operator()(double x, double y)
	{
		set_x(x);
		set_y(y);
		return *this;
	}

	// methods
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}

	void print() const
	{
		cout << "x = " << x << "\ty = " << y << endl;
	}

};

double distance( Point& A, Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

Point operator+(Point& left,  Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}

bool operator==(Point& left, Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;*/
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}

std::ostream& operator<<(std::ostream& os, Point& obj)
{
	return os << "X = " << obj.get_x() << "\tY = " << obj.get_x();
}

 std::istream& operator>>(std::istream& is, Point& obj)
{
	 double x, y;
	 is >> x >> y;
	 obj(x, y);
	 return is;
}


//#define DISTANCE_CHECK
//#define CONSTRUCTOR_CHECK
//#define ASSIGNMENT_CHEC
//#define OPERATORS_CHECK

void main()
{
	setlocale(LC_ALL, "");

#ifdef ASSIGNMENT_CHEC
	Point A, B, C;
	A = B = C = Point(2, 3);
#endif // ASSIGNMENT_CHEC

#ifdef DISTANCE_CHECK


	Point A;

	A.set_x(2);
	A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point B;

	B.set_x(7);
	B.set_y(8);
	cout << B.get_x() << "\t" << B.get_y() << endl;

	cout << "от А до В " << A.distance(B) << endl;
	cout << "от В до А " << B.distance(A) << endl;
	cout << "от А до В " << distance(A, B) << endl;
	cout << "от В до А " << distance(B, A) << endl;
#endif // DISTANCE_CHECK

#ifdef CONSTRUCTOR_CHECK

	Point A;
	A.print();

	Point B = 5;
	B.print();

	Point C = (2, 3);
	C.print();

	Point D = C;
	D.print();

#endif // CONSTRUCTOR_CHECK

#ifdef OPERATORS_CHECK
	Point A(2, 3);
	Point B(7, 8);
	Point C = A + B;
	A.print();
	B.print();
	C.print();
	Point D = C++;
	D.print();
	C.print();
	
	cout << (C == D) << endl;
#endif // OPERATORS_CHECK

	Point A(2, 3);
	cout << "Введите кординаты точки:"; cin >> A;


	cout << A << endl;
	


}
