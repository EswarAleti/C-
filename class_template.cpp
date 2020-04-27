#include<iostream>
using namespace std;

template<class T>
class Calculator
{
	private:
		T a;
		T b;
	public:
		Calculator(T a, T b)
		{
			this->a=a;
			this->b=b;
		}
		T add();
};

template<class T>
T Calculator<T>::add()
{
	return a+b;
}

int main()
{
	Calculator<int> calc1(1,2);
	cout<<calc1.add()<<endl;
	Calculator<float> calc2(1.45,2.25);
	cout<<calc2.add()<<endl;
	Calculator<double> calc3(1.167,2.24);
	cout<<calc3.add()<<endl;
	Calculator<string> calc4("Hello","World");
	cout<<calc4.add()<<endl;
	return 0;
}