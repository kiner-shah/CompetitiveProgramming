#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
struct mixes {
    char one, two, three;
};
struct nomixes {
    char one , two;
};
char search(struct mixes a[], int n, char x, char y) {
    char ans = '0';
    for(int i = 0; i < n; i++) {
        if((a[i].one == x && a[i].two == y) || (a[i].one == y && a[i].two == x)) {
            ans = a[i].three; break;
        }
    }
    return ans;
}
set<char> searchnm(struct nomixes a[], int n, char x) {
    set<char> ans;
    for(int i = 0; i < n; i++) {
        if(a[i].one == x || a[i].two == x) {
            char ansc = a[i].one == x ? a[i].two : a[i].one;
            ans.insert(ansc);
        }
    }
    return ans;
}
int main() {
	int t, i = 0, d, c, n;
	string x, y, z;
	cin>>t;
	while(i < t) {
	    cin>>c;
	    vector<char> finallist;
	    struct mixes mixstr[c];
	    for(int j = 0; j < c; j++) {
	        cin>>x;
	        mixstr[j].one = x[0];
	        mixstr[j].two = x[1];
	        mixstr[j].three = x[2]; //cout<<mixstr[j].one<<" "<<mixstr[j].two<<" "<<mixstr[j].three<<endl;
	    }
	    cin>>d;
	    struct nomixes nmstr[d];
	    for(int j = 0; j < d; j++) {
	        cin>>y;
	        nmstr[j].one = y[0];
	        nmstr[j].two = y[1]; //cout<<nmstr[j].one<<" "<<nmstr[j].two<<endl;
	    }
	    cin>>n>>z;
	    assert(z.length() == n);
	    for(int j = 0; j < n; j++) {
	        char tempc = z[j];
	        if(finallist.size() > 0) {
	        	char ans1 = search(mixstr, c, finallist[finallist.size() - 1], tempc);
	        	if(ans1 != '0') {
	        		finallist.pop_back();
	        		finallist.push_back(ans1);
	        		continue;
	        	}
	        	set<char> ans2 = searchnm(nmstr, d, tempc);
	        	if(ans2.size() > 0) {
	        		bool cflag = false;
	        		for(char kk : ans2) {
				for(int k = 0; k < finallist.size(); k++) {
					if(finallist[k] == kk) {
						cflag = true; break;
					}
				}
		        		if(cflag) {
		        			break;
		        		}
	        		}
	        		if(cflag) {
	        			finallist.clear(); continue;
	        		}
 	        	}
	        }
	        finallist.push_back(tempc);
	        //for(int k = 0; k < finallist.size(); k++) cout<<finallist[k]<<" "; cout<<endl;
	    }
	    cout<<"Case #"<<i+1<<": [";
	    if(finallist.size() > 0) {
	    	for(int j = 0; j < finallist.size() - 1; j++) cout<<finallist[j]<<", ";
			cout<<finallist[finallist.size() - 1]<<"]\n";
	    }
	    else cout<<"]\n";
	    finallist.clear();
 	    i++;
	}
	return 0;
}
