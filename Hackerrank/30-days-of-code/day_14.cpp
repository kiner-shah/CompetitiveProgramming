// Scope
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;

  	public:
  	int maximumDifference;

	// Add your code here
    Difference(vector<int> arr) {
        for(int i = 0; i < arr.size(); i++) elements.push_back(arr[i]);
    }
    void computeDifference() {
        vector<int> temp_arr;
        for(int i = 0; i < elements.size(); i++) temp_arr.push_back(elements[i]);
        sort(temp_arr.begin(), temp_arr.end());
        // for(int i = 0; i < temp_arr.size(); i++) cout << temp_arr[i] << " " ;
        maximumDifference = temp_arr[temp_arr.size() - 1] - temp_arr[0];
    }

}; // End of Difference class

int main() {
    int N;
    cin >> N;

    vector<int> a;

    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;

        a.push_back(e);
    }

    Difference d(a);

    d.computeDifference();

    cout << d.maximumDifference;

    return 0;
}