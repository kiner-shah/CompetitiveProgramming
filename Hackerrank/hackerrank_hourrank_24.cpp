#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>
using namespace std;

// Return the minimum number of characters to make the password strong
int strong_password() {
	int n; string password;
	cin >> n >> password;
    smatch m;
    int count = 0;
    bool lflag = false, uflag = false, dflag = false, sflag = false;
    if(password.find_first_of("0123456789") == string::npos) dflag = true;
    //cout<<count<<endl;
    if(password.find_first_of("abcdefghijklmnopqrstuvwxyz") == string::npos) lflag = true;
    //cout<<count<<endl;
    if(password.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ") == string::npos) uflag = true;
    //cout<<count<<endl;
    if(password.find_first_of("!@#$%^&*()-+") == string::npos) sflag = true;
    
    if(n < 6) {
        if(!dflag) {
            if(!uflag) {
                if(!lflag) {
                    if(!sflag) {
                        count += 6 - n;
                    }
                }    
            }
        }
    }
    if(dflag) count++;
    if(sflag) count++;
    if(lflag) count++;
    if(uflag) count++;
    if(n + count < 6) {
        count += (6 - count - n);
    }
    cout << count << endl;
}

int main() {
	// strong_password();
    return 0;
}
