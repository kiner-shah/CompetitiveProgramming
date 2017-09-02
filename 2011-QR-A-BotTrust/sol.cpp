#include <iostream>
using namespace std;

int main() {
	int k, l, button, p, q, t, n, i = 0, curo, curb;
	cin>>t; char c; string d;
	int o[100], b[100];
	while (i < t) {
		cin >> n;
		k = 0; l = 0; p = 0; q = 0;
		curo = 1; curb = 1;
		d = "";
		while(n-- > 0) {
			cin>>c>>button;
			if(c == 'O') { o[k] = button; k++; }
			else { b[l] = button; l++; }
			d += c;
		}
		int j = 0, len = d.length(), time1 = 0;
		while(j < len) {
		    //cout<<p<<" "<<k<<" "<<q<<" "<<l<<endl;
		    //cout<<time1<<" "<<curo<<" "<<o[p]<<" "<<curb<<" "<<b[q]<<endl;
			if(d[j] == 'O') {
				if(curo < o[p]) curo++;
				else if(curo > o[p]) curo--;
				else if(curo == o[p]) { j++; p++; }
				if(curb < b[q]) curb++;
				else if(curb > b[q]) curb--;
				else if(curb == b[q]) { }
				time1++;
			}
			else {
				if(curb < b[q]) curb++;
				else if(curb > b[q]) curb--;
				else if(curb == b[q]) { j++; q++; }
				if(curo < o[p]) curo++;
				else if(curo > o[p]) curo--;
				else if(curo == o[p]) { }
				time1++;
			}
			if(p >= k || q >= l) break;
		}
		if(p >= k && q < l) {
		    while(q < l) {
		        //cout<<time1<<" REACHED REACHED "<<curb<<" "<<b[q]<<endl;
		        if(curb < b[q]) curb++;
			    else if(curb > b[q]) curb--;
			    else if(curb == b[q]) { q++; }
			    time1++;
		    }
		}
		if(q >= l && p < k) {
		    while(p < k) {
		        //cout<<time1<<" "<<curo<<" "<<o[p]<<" REACHED REACHED"<<endl;
		        if(curo < o[p]) curo++;
			    else if(curo > o[p]) curo--;
			    else if(curo == o[p]) { p++; }
			    time1++;
		    }
		}
		cout<<"Case #"<<i+1<<": "<<time1<<endl;
		i++;
	}
	return 0;
}