#include<iostream>
#include<vector>
using namespace std;

class Item
{
	//Private data members
	private:
		string name;
		int price;
		vector<Item> items;
	//public functions
	public:
		//Non-parameterized constructor
		Item()
		{

		}
		//parameterized constructor
		Item(string name, int price)
		{
			this->name=name;
			this->price=price;
		}
		//FUnction declarations
		void addItem(Item item);
		vector<Item> getTop5(int price);
		string getName();
		int getPrice();
};

void Item::addItem(Item item)
{
	//Add item object to vector of Items
	items.push_back(item);
}

vector<Item> Item::getTop5(int price)
{
	//declaration of vector
	vector<Item> top5;
	int count=0;
	//Iterate till end of list or till we got top5 elements
	for(int i=0;i<items.size() && count<5;i++)
	{
		//If the item is affordable with $100 then select that item
		if(items[i].price<=100)
		{
			top5.push_back(items[i]);
			//Increment the count
			count++;
		}
	}
	//return the resultant vecor
	return top5;
}

//return the name of object
string Item::getName()
{
	return name;
}

//return the price of object
int Item::getPrice()
{
	return price;
}

int main()
{
	//Declaration of objects
	Item item;
	Item item1("MObile" , 150);
	Item item2("Refrigirator" , 70);
	Item item3("Air Cooler" , 170);
	Item item4("clothes" , 30);
	Item item5("Calculator" , 20);
	Item item6("Home Theatre" , 60);
	Item item7("Headset" , 45);
	Item item8("Textbooks" , 101);
	Item item9("Tablet" , 80);
	Item item10("Laptop" , 500);
	Item item11("Belt" , 50);
	Item item12("Earphones" , 115);
	Item item13("SmartWatch" , 550);
	Item item14("Airpods" , 150);
	
	//Adding above objects to vector
	item.addItem(item1);
	item.addItem(item2);
	item.addItem(item3);
	item.addItem(item4);
	item.addItem(item5);
	item.addItem(item6);
	item.addItem(item7);
	item.addItem(item8);
	item.addItem(item9);
	item.addItem(item10);
	item.addItem(item11);
	item.addItem(item12);
	item.addItem(item13);
	item.addItem(item14);

	//functionc alling to get top 5 items
	vector<Item> top5=item.getTop5(100);
	//Output the result
	for(int i=0;i<top5.size();i++)
	{
		cout<<top5[i].getName()<<" "<<top5[i].getPrice()<<endl;
	}
	return 0;
}