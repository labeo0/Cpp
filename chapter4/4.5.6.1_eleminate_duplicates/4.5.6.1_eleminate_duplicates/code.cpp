//Remove duplicates
#include <string>
#include <iostream>

using namespace std;

string eraseDuplicate(string sentence)
{
	string str, res = "";
	bool isReplaced;
	int check = sentence.find(" ");
	while(check != string::npos)
	{
		str = sentence.substr(0,check);//take first word
		res+=str+" ";
		sentence = sentence.substr(check+1,string::npos);//remove first word from sentence
		do{
			isReplaced = false;
			if(sentence.find(str)!=string::npos)//check if word has duplicate
			{
				sentence.replace(sentence.find(str),str.length()+1,"");//remove duplicate
				isReplaced = true;
			}
		}while(isReplaced);
		check = sentence.find(" ");//where next word finishes
	}
	return res+sentence;//+sentence/ to capture the last word/ if i dont forget i will corect it
}
int main()
{
	string text ;
	getline(cin, text);
	string temp, res = "";

	int check = text.find(",");
	while(check!=string::npos)//divide sentence by commas and there for duplicate separetly
	{
		temp = text.substr(0,check);
		res+=eraseDuplicate(temp)+", ";
		text = text.substr(check+2,string::npos);//+2 to not capture comma and space ", "
		check = text.find(",");
	}
	res+=eraseDuplicate(text);//if there is no commas/and cycle up there dont procces substring after last comma:)
	
	cout<<"RESULTS:"<<res<<":\n";
	system("pause");
	return 0;
}