#include<iostream>
using namespace std;
//using class as user defined datatype 
class Student {
public:
    string name;
    int rno;
    float marks;
    //constructor
    Student(string n, int r, float m) {
        name=n;
        rno=r;
        marks=m; 
    }
};
void change(Student &s) {
    s.name="jairaj singh";
}
int main() {
    Student s("anish bakshi",76,93.4); //declaration with initialization

    Student* ptr=&s;
    
    //declaration + initialization
    /*
    Student s;
    s.name="anish bakshi";
    s.rno=76;
    s.marks=93.4;
    */
    cout<<s.name<<endl;
    change(s);
    //the name will not get updated coz its pass by value  
    //if you want to change then use & and its called pass by reference
    cout<<s.name <<endl;

    /*

    //using pointers 
    int x=6;
    int* p=&x;
    cout<<*p; //prints value
    cout<<p; //prints addr

    *p=8; //using deferencing op 
    cout<<x; 
    */

    //changing name rno per using pointers
    cout<<s.name<<endl;
    //(*ptr).name = "mohit"; //way 1
    ptr->name="mohit";       //way 2
    cout<<s.name<<endl;





    

}