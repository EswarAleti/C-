#include<iostream>
#include<vector>
using namespace std;

class Atom
{
	private:
		int number;
		string name;
		string abbreviation;
		float weight;
	public:
		void setNumber(int number)
		{
			this->number = number;
		}
		void setName(string name)
		{
			this->name = name;
		}
		void setAbbreviation(string abbreviation)
		{
			this->abbreviation = abbreviation;
		}
		void setWeight(float weight)
		{
			this->weight = weight;
		}
		int getNumber()
		{
			return this->number;
		}
		string getName()
		{
			return this->name;
		}
		string getAbbreviation()
		{
			return this->abbreviation;
		}
		float getWeight()
		{
			return this->weight;
		}
};

int main()
{
	Atom hydrogen;
	hydrogen.setNumber(1);
	hydrogen.setName("H");
	hydrogen.setAbbreviation("Hydrogen");
	hydrogen.setWeight(1.008);
	Atom oxygen;
	oxygen.setNumber(8);
	oxygen.setName("O");
	oxygen.setAbbreviation("Oxygen");
	oxygen.setWeight(15.999);
	vector<Atom> water;
	water.push_back(hydrogen);
	water.push_back(hydrogen);
	water.push_back(oxygen);
	return 0;
}