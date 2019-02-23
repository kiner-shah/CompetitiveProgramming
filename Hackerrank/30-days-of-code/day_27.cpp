// Testing
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

int minimum_index(vector<int> seq) {
    if (seq.empty()) {
        throw invalid_argument("Cannot get the minimum value index from an empty sequence");
    }
    int min_idx = 0;
    for (int i = 1; i < seq.size(); ++i) {
        if (seq[i] < seq[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

#include <cstdlib>
#include <climits>
#include <cstring>
vector<int> v;
int pos;
int min1;
class TestDataEmptyArray {
public:
    static vector<int> get_array() {
        // complete this function
        v.clear();
        return v;
    }

};

class TestDataUniqueValues {
public:
    static vector<int> get_array() {
        // complete this function
        v.clear();
        int x[10], xcnt = 0;
        srand(time(NULL));
        memset(x, 0, sizeof(x));
        min1 = INT_MAX, pos = -1;
        while(true) {
            int k = rand() % 10 + 1;
            if(x[k - 1] != 1) {
                v.push_back(k);
                x[k - 1] = 1;
                if(min1 > k) {
                    min1 = k;
                    pos = xcnt;
                }
                xcnt++;
            }
            if(xcnt == 10) break;
        }
        return v;
    }

    static int get_expected_result() {
        // complete this function
        //cout << "UV " << pos << endl;
        return pos;
    }

};

class TestDataExactlyTwoDifferentMinimums {
public:
    static vector<int> get_array() {
        // complete this function
        v.clear();
        int x[10] = {3, 2, 4, 5, 1, 7, 8, 9, 1, 10};
        min1 = INT_MAX, pos = -1;
        for(int i = 0; i < 10; i++) {
            v.push_back(x[i]);
            if(min1 > x[i]) {
                min1 = x[i];
                pos = i;
            }
        }
        return v;
    }

    static int get_expected_result() {
        // complete this function
        //cout << "ETD " << pos << endl;
        return pos;
    }

};


void TestWithEmptyArray() {
    try {
        auto seq = TestDataEmptyArray::get_array();
        auto result = minimum_index(seq);
    } catch (invalid_argument& e) {
        return;
    }
    assert(false);
}

void TestWithUniqueValues() {
    auto seq = TestDataUniqueValues::get_array();
    assert(seq.size() >= 2);

    assert(set<int>(seq.begin(), seq.end()).size() == seq.size());

    auto expected_result = TestDataUniqueValues::get_expected_result();
    auto result = minimum_index(seq);
    assert(result == expected_result);
}

void TestWithExactlyTwoDifferentMinimums() {
    auto seq = TestDataExactlyTwoDifferentMinimums::get_array();
    assert(seq.size() >= 2);

    auto tmp = seq;
    sort(tmp.begin(), tmp.end());
    assert(tmp[0] == tmp[1] and (tmp.size() == 2 or tmp[1] < tmp[2]));

    auto expected_result = TestDataExactlyTwoDifferentMinimums::get_expected_result();
    auto result = minimum_index(seq);
    assert(result == expected_result);
}

int main() {
    TestWithEmptyArray();
    TestWithUniqueValues();
    TestWithExactlyTwoDifferentMinimums();
    cout << "OK" << endl;
    return 0;
}