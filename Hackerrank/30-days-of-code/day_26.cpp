// Nested Logic
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int actuald, actualm, actualy;
    int expectedd, expectedm, expectedy;
    cin >> actuald >> actualm >> actualy;
    cin >> expectedd >> expectedm >> expectedy;
    int fine = 0;
    if(actualy > expectedy) fine = 10000;
    else if(actualy < expectedy) fine = 0;
    else if(actualy == expectedy && actualm > expectedm) fine = 500 * (actualm - expectedm);
    else if(actualy == expectedy && actualm < expectedm) fine = 0;
    else if(actualy == expectedy && actualm == expectedm && actuald > expectedd) fine = 15 * (actuald - expectedd);
    else fine = 0;
    cout << fine;
    return 0;
}