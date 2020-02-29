#include<iostream>
using namespace std;

int main()
{
	//String constant
	string s="For God so loved the world that he gave his one and only Son, that whoever believes in him shall not perish but have eternal life. For God did not send his Son into the world to condemn the world, but to save the world through him. Whoever believes in him is not condemned, but whoever does not believe stands condemned already because they have not believed in the name of God's one and only Son. This is the verdict: Light has come into the world, but people loved darknes instead of light because their deeds were evil. Everyone who does evil hates the light, and will not come into the light for fear that their  deeds will be exposed 21 But whoever lives by the truth comes into the light, so that it may be seen plainly that what they have done has been done in the sight of God.";

	//User input
	cout<<"Enter a word or phrase: ";
	string input;
	getline(cin,input);

	size_t found=-1;
	int count=0;
	//Iterate untill word/phrase not found
	while(true)
	{
		//find word/phrase in string from index found+1 and assign the result to found variable
		found = s.find(input,found+1);
		//If found increment the count
		if (found != string::npos)
		{
			count++;
		}
		//If not found then break the loop
		else
		{
			break;
		}
	}
	cout<<input<<" occurs "<<count<<" times."<<endl;
}