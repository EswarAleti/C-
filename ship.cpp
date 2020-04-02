#include<iostream>
using namespace std;
class Ship
{
	private:
	string name;
	string year;
	public:
		//Empty constructor
		Ship()
		{

		}
		//Mutators
		void setName(string name);
		void setYear(string year);
		//Accessors
		string getName();
		string getYear();
		//Virtual display function
		void display();

};

//setName() definition
void Ship::setName(string name)
{
	this->name = name;
}

//setYear() definition
void Ship::setYear(string year)
{
	this->year = year;
}

//getName() definition
string Ship::getName()
{
	return name;
}

//getYear() definition
string Ship::getYear()
{
	return year;
}

//display() defintion
void Ship::display()
{
	cout<<name<<" "<<year<<endl;
}

//main function
int main()
{
	//Creating object
	Ship ship1;
	//Setting details of ship
	ship1.setName("Titanic");
	ship1.setYear("1949");
	//Call virtual display
	ship1.display();
	return 0;
}