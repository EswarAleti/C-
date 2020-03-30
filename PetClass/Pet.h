using namespace std;
class Pet
{
	private:
		//data mambers
		string name;
		string type;
		int level;
	public:
		//Default constructor
		Pet()
		{
			name="Buddy";
			type="dog";
			level=1;
		}
		//Parameterized constructor
		Pet(string name,string type,int level)
		{
			this->name=name;
			this->type=type;
			this->level=level;
		}
		void PrintInfo();
		void TimePasses();
		void FeedPet();
};

void Pet::PrintInfo()
{
	cout<<"A "<<type<<" named "<<name<<" who is hungry level "<<level<<endl;
}

void Pet::TimePasses()
{
	level++;
}

void Pet::FeedPet()
{
	level--;
}