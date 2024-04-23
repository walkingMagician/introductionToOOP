#include <iostream>


using namespace std;

double distance(class Point A);

class Point
{
	double x;
	double y;
public:

	double distance_x() const
	{
		return x;
	}
	double distance_y() const
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
	
};

void main()
{
	setlocale(LC_ALL, "");

	Point A;


	double z, c;
	cout << "растояние x - "; cin >> z;
	cout << "растояние y - "; cin >> c;

	A.set_x(z);
	A.set_y(c);

	cout << "расстояние до точки x =: " << A.distance_x() << endl;
	cout << "расстояние до точки y =: " << A.distance_y() << endl;
	cout << "расстояние между точкой x и точкой y =: " << distance(A) << endl;

}

double distance(class Point A)
{
	double c = 0;
	c = max(A.distance_x(), A.distance_y()) - min(A.distance_x(), A.distance_y());

	return c;
}
