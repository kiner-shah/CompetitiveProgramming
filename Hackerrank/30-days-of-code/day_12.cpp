// Inheritance
#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n";
		}

};

class Student :  public Person {
	private:
		vector<int> testScores;
	public:
        /*
        *   Class Constructor
        *
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
        Student(string fn, string ln, int _id, vector<int> scores) : Person(fn, ln, _id) {
            for(int x : scores) testScores.push_back(x);
        }
        /*
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
        char calculate() {
            char grade;
            int sum = 0, len = testScores.size();
            for(int score : testScores) sum += score;
            double average = (double) sum / (double) len;
            if(average >= 90 && average <= 100) grade = 'O';
            else if(average >= 80 && average < 90) grade = 'E';
            else if(average >= 70 && average < 80) grade = 'A';
            else if(average >= 55 && average < 70) grade = 'P';
            else if(average >= 40 && average < 55) grade = 'D';
            else if(average < 40) grade = 'T';
            return grade;
        }
};

int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;
  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}
	Student* s = new Student(firstName, lastName, id, scores);
	s->printPerson();
	cout << "Grade: " << s->calculate() << "\n";
	return 0;
}