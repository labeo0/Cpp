#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
	string name;
	int age;
	string university;
};
void print(Person* person)
{
	cout << person->name << " is "<< person->age << " years old. " <<"Studies in "<< person->university<<endl;
}
int main()
{
	Person person;
	person.name = "Harry";
	person.age = 23;
	person.university = "KNU";
	cout << "Meet " << person.name;
	print(&person);
	cout<<person.name<<" says "<<person.university<<" is the best\n";
	person.age++;
	
	cout<<person.name<<" is older now"<<endl;
	print(&person);

	system("pause");
	return 0;
}
