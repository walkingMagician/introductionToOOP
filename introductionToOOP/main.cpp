#include <iostream>


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
	// конструкторы
	
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
	// операторы 

	Point operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "copy assigmen:\t" << this << endl;
		return *this;
	}

	// математика
	double distance(const Point other)const
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

double distance(Point A, Point B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

//#define DISTANCE_CHECK
//#define CONSTRUCTOR_CHECK

void main()
{
	setlocale(LC_ALL, "");


	Point A, B, C;
	A = B = C = Point(2, 3);
	


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
}
