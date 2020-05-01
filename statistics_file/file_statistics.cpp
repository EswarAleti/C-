#include<iostream>
#include<fstream>
#include<list> 
#include<algorithm>
using namespace std;

//This function removes punctuation and conver word to lower case
string filter_word(string word)
{
	string res = "";
	//For each character of word
	for(int i=0;i<word.length();i++)
	{
		//replace - with white space
		if(word[i]=='-')
		{
			res+=' ';
		}
		//If character is not a punctuation
		else if(!ispunct(word[i]))
		{
			//Convert character to lower case and append to results
			res = (word[i]>='A' && word[i]<='Z')?res+(char)(word[i]+32):res+word[i];
		}
	}
	//Return the filtered string
	return res;
}

//This function returns true if string has digit
bool has_number(string word)
{
	for(int i=0;i<word.length();i++)
	{
		//If character is digit return true
		if(word[i]>='0' && word[i]<='9')
		{
			return true;
		}
	}
	//If word doesn't have digit return false
	return false;
}

int main()
{
	//Opening file
	ifstream infile("Rats.txt");
	if(!infile.is_open())
	{
		cout<<"Cannot open file"<<endl;
		return 0;	
	}

	string word;
	int word_counter=0,four_letter_word_counter=0;
	list<string> words;
	while(infile>>word)
	{
		//If word has number then skip the iteration
		if(has_number(word))
		{
			continue;
		}
		//Filter the word
		word=filter_word(word);
		//If word not exist in list
		if(find(words.begin(), words.end(), word)==words.end())
		{
			//Insert into list
			words.push_back(word);
			//If word is of four letter then increment counter by 1
			four_letter_word_counter = word.length()==4 ? four_letter_word_counter+1:four_letter_word_counter;
		}
		//Increment word_counter by 1
		word_counter++;
	}
	//Close the file
	infile.close();

	//Open file to write
	ofstream outfile("reports.txt");
	//Write statistics into file
	outfile<<to_string(word_counter)+"\n";
	outfile<<to_string(words.size())+"\n";
	outfile<<to_string(four_letter_word_counter)+"\n";
	//Close the file
	outfile.close();
	return 0;
}