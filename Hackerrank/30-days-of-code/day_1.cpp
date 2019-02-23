// Data types
#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";


    // Declare second integer, double, and String variables.
    int a;
    double b;
    string c;
    // Read and save an integer, double, and String to your variables.
    cin >> a;
    // Print the sum of both integer variables on a new line.
    cin >> b;
    // Print the sum of the double variables on a new line.
    getline(cin, c);
    getline(cin, c);
    // Concatenate and print the String variables on a new line
    // The 's' variable above should be printed first.
    cout << a + i << endl;
    printf("%.1f\n", b + d);
    cout << s + c;

    return 0;
}