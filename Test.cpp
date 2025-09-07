#include <iostream>
#include <string>
using namespace std;

struct student
{
    string name;
    int age;
    char grade; 
};

int main()
{
    student student1;
    student1.name = "Adam";
    student1.age = 19;
    student1.grade = 'A';


cout << "Name: " << student1.name << endl;
cout << "Age: " << student1.age << endl;
cout << "Grade: " << student1.grade << endl;

    return 0;  
}