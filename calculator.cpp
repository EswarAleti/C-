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
		T sub();
		T mult();
		T division();
};

template<class T>
T Calculator<T>::add()
{
	return a+b;
}

template<class T>
T Calculator<T>::sub()
{
	return a-b;
}

template<class T>
T Calculator<T>::mult()
{
	return a*b;
}

template<class T>
T Calculator<T>::division()
{
	return a/b;
}

int main()
{
	Calculator<int> calc1(16,9);
	cout<<"Integer addition: "<<calc1.add()<<endl;
	cout<<"Integer subtractions: "<<calc1.sub()<<endl;
	cout<<"Integer Multiplication: "<<calc1.mult()<<endl;
	cout<<"Integer Division: "<<calc1.division()<<endl;
	
	Calculator<float> calc2(20.25,2.25);
	cout<<"Float addition: "<<calc2.add()<<endl;
	cout<<"Float subtractions: "<<calc2.sub()<<endl;
	cout<<"Float Multiplication: "<<calc2.mult()<<endl;
	cout<<"Float Division: "<<calc2.division()<<endl;

	Calculator<double> calc3(1000,2.5);
	cout<<"Double addition: "<<calc3.add()<<endl;
	cout<<"Double subtractions: "<<calc3.sub()<<endl;
	cout<<"Double Multiplication: "<<calc3.mult()<<endl;
	cout<<"Double Division: "<<calc3.division()<<endl;
	
	return 0;
}