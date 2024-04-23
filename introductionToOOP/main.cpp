#include <iostream>
using std::cout;
using std::cin;
using std::endl;

//#define STRUCT_POINT

class Point
{
	double x;
	double y;
public:

	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}



};

void main()
{
	setlocale(LC_ALL, "");
	
#ifdef STRUCT_POINT
	Point A;
	
	A.x = 2;
	A.y = 5;

	cout << "x = " << A.x << " y = " << A.y << endl;

	Point* pa = &A;
	cout << pa->x << "\t" << pa->y << endl;
#endif // STRUCT_POINT


	Point A;
	A.set_x(6);
	A.set_y(4);

	cout << A.get_x() << "\t" << A.get_y() << endl;

}
