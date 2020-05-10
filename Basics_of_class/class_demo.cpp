#include<iostream>
using namespace std;

// Global variables
int gvar1=12,gvar2=14;
static double PI=3.14159;

class QuestionA
{
	public:
		// funA definition
		int funA(int a, int b, int c)
		{
			// If a is max then return a
			if(a>b && a>c)
			{
				return a;
			}
			// Return maximum among b and c
			return b>c?b:c;
		}
		// funB definition
		double funB(double a, double b, double c)
		{
			// Find and return the sum of a,b and c
			return a+b+c;
		}
		// funC definition
		void funC(int &psum)
		{
			// Find and assigm maximum of gvar1 and gvar2 to psum
			psum = gvar1>gvar2?gvar1:gvar2;
			// Print psum
			cout<<"value of psum: "<<psum<<endl;
		}
		// funD definition
		static double funD(int radius)
		{
			return 4.0/3.0*PI*radius*radius*radius;
		}
};

int main()
{
	// Object creations
	QuestionA obj;
	// Function calling and output printing
	int max = obj.funA(8,9,7);
	cout<<"Max value: "<<max<<endl;
	double sum = obj.funB(1.25, 4.12, 9.23);
	cout<<"Sum: "<<sum<<endl;
	int psum=0;
	obj.funC(psum);
	double volume = obj.funD(7);
	cout<<fixed<<"Volume: "<<volume<<endl;
	return 0;
}