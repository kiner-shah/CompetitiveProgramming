// Class vs instance
#include <iostream>
using namespace std;

class Person{
    public:
        int age;
        Person(int initialAge);
        void amIOld();
        void yearPasses();
    };

    Person::Person(int initialAge) {
        // Add some more code to run some checks on initialAge
        if(initialAge >= 0) age = initialAge;
        else {
            age = 0;
            cout << "Age is not valid, setting age to 0.\n";
        }
    }

    void Person::amIOld(){
        // Do some computations in here and print out the correct statement to the console
        cout << (age < 13 ? "You are young.\n" : (age >= 13 && age < 18 ? "You are a teenager.\n" : "You are old.\n"));
    }

    void Person::yearPasses(){
        // Increment the age of the person in here
        age++;
    }

int main(){
    int t;
	int age;
    cin >> t;
    for(int i=0; i < t; i++) {
    	cin >> age;
        Person p(age);
        p.amIOld();
        for(int j=0; j < 3; j++) {
        	p.yearPasses();
        }
        p.amIOld();

		cout << '\n';
    }

    return 0;
}