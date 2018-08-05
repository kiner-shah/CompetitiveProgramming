/*
 * File:   tourist.cpp
 * Author: Kiner Shah
 *
 * Created on 07 June, 2018, 10:42 AM
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int convertToLL(string i) {
    std::stringstream ss;
    ss << i;
    LL x;
    ss >> x;
    return x;
}

typedef struct TMP_STRCT {
    string s;
    int pri;
    LL count;
} temp_strct;


bool prob_comp(temp_strct a, temp_strct b) {
    if(a.count < b.count) return true;
    else if(a.count == b.count && a.pri < b.pri) return true;
    return false;
}
bool pri_comp(temp_strct a, temp_strct b) {
    if(a.pri < b.pri) return true;
    return false;
}
struct timespec diff(timespec start, timespec end)
{
	struct timespec temp;
	if ((end.tv_nsec-start.tv_nsec)<0) {
		temp.tv_sec = end.tv_sec-start.tv_sec-1;
		temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
	} else {
		temp.tv_sec = end.tv_sec-start.tv_sec;
		temp.tv_nsec = end.tv_nsec-start.tv_nsec;
	}
	return temp;
}
int main() {
   ifstream in;
   ofstream out;
   in.open("input.in");
   out.open("output.txt");
   string line;
   getline(in, line);
   int t = (int) convertToLL(line);
   int i = 0, n, k;
   LL v;
   while(i < t) {
       getline(in, line);
//        cout << line << endl;
       stringstream ss;
       ss << line;
       ss >> n >> k >> v;
       // take n inputs
       string s;
       vector<temp_strct > m;
       for(int l = 0; l < n; l++) {
           getline(in, s);
           temp_strct x;
           x.s = s;
           x.pri = l;
           x.count = 0;
           m.push_back(x);
       }
//        for(temp_strct x : m) cout << x.s << " " << x.pri << " " << x.count << endl;
//        cout << endl;
       // choose first k of them and find vth output as per requirement
       out << "Case #" << i + 1 << ": ";
       vector<vector<temp_strct> > u;
       if(k == n) {
           for(int l = 0; l < k; l++) out << m[l].s << " "; out << endl;
       }
       else {
           LL j = 0;
           while(j < n) {
               vector<temp_strct> temp_vct;
               for(int l = 0; l < k; l++) {
                   m[l].count++;
                   temp_vct.push_back(m[l]);
               }
               u.push_back(temp_vct);
//                for(temp_strct xx : temp_vct) cout << xx.s << " "; cout << endl;
               sort(m.begin(), m.end(), prob_comp);
               j++;
           }
           if(v >= n) {
               int ind = (v - 1) % n;
//                cout << "IND = " << ind << endl;
               sort(u[ind].begin(), u[ind].end(), pri_comp);
               for(int l = 0; l < k; l++) out << u[ind][l].s << " "; out << endl;
           }
           else {
//                cout << "V-1 = " << v - 1 << endl;
               sort(u[v - 1].begin(), u[v - 1].end(), pri_comp);
               for(int l = 0; l < k; l++) out << u[v - 1][l].s << " "; out << endl;
           }
       }
       i++;
   }
   in.close();
   out.close();
   return 0;
}