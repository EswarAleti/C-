#include<iostream>
#define PI 3.14159
using namespace std;

class Circle
{
	private:
		double radius;
		double x_cord;
		double y_cord;
	public:
		Circle()
		{
			radius=0;
			x_cord=0;
			y_cord=0;
		}
		void setRadius(double r)
		{
			radius=r;
		}
		void setCenter(double x, double y)
		{
			x_cord=x;
			y_cord=y;
		}
		double getRadius()
		{
			return radius;
		}
		pair<double, double> getCenter()
		{
			pair<double, double> center;
			center.first=x_cord;
			center.second=y_cord;
			return center;
		}
		double getArea()
		{
			return PI*radius*radius;
		}
		double getPerimeter()
		{
			return 2*PI*radius;
		}
};

int main()
{
	Circle circle1;
	circle1.setRadius(14);
	circle1.setCenter(4,4);
	cout<<"Radius: "<<circle1.getRadius()<<endl;
	cout<<"Center: ("<<circle1.getCenter().first<<","<<circle1.getCenter().second<<")"<<endl;
	cout<<"Area: "<<circle1.getArea()<<endl;
	cout<<"Perimeter: "<<circle1.getPerimeter()<<endl;
	return 0;
}