#include <bits/stdc++.h>
using namespace std;
int find_parent(int parent[], int p) {
    if(parent[p] == p) return p;
    else return find_parent(parent, parent[p]);
}
void membersInTheLargestGroups(int n, int m, int a, int b, int f, int s, int t) {
    // Print the names of the students in all largest groups or determine if there are no valid groups.
    string name;
    int grade;
    int grades[n][3];
    for(int i = 0; i < n; i++) { grades[i][0] = grades[i][1] = grades[i][2] = 0; }
    int size[n], max1 = -1;
    vector<int> posar;
    map<string, int> pos;
    int parent[n];
    for(int i = 0; i < n; i++) {
        cin >> name >> grade;
        pos.insert(make_pair(name, i));
        grades[i][grade - 1] = 1;
        size[i] = 1;
        parent[i] = i;
    }
    string p, q;
    for(int i = 0; i < m; i++) {
        cin >> p >> q;
        int posp = find_parent(parent, pos[p]), posq = find_parent(parent, pos[q]);
        if(posp != posq) {
            if(size[posp] + size[posq] <= b) {
                if(grades[posp][0] + grades[posq][0] <= f &&
                   grades[posp][1] + grades[posq][1] <= s &&
                   grades[posp][2] + grades[posq][2] <= t) {
                    if(size[posp] > size[posq]) {
                        /*for(pair<string, int> pp : pos) {
                            if(pp.second == posq) pos[pp.first] = posp;
                        }*/
                        
                        parent[posq] = posp;
                        
                        size[posp] += size[posq];
                        size[posq] = 0;
                        
                        grades[posp][0] += grades[posq][0]; grades[posq][0] = 0;
                        grades[posp][1] += grades[posq][1]; grades[posq][1] = 0;
                        grades[posp][2] += grades[posq][2]; grades[posq][2] = 0;
                        
                        if(max1 <= size[posp] && size[posp] >= a) {
                            if(max1 < size[posp]) posar.clear(); 
                            posar.push_back(posp);
                            max1 = size[posp];
                        }
                    }
                    else {
                        /*for(pair<string, int> pp : pos) {
                            if(pp.second == posp) pos[pp.first] = posq;
                        }*/
                        
                        parent[posp] = posq;
                        
                        size[posq] += size[posp];
                        size[posp] = 0;
                        
                        grades[posq][0] += grades[posp][0]; grades[posp][0] = 0;
                        grades[posq][1] += grades[posp][1]; grades[posp][1] = 0;
                        grades[posq][2] += grades[posp][2]; grades[posp][2] = 0;
                        
                        if(max1 <= size[posq] && size[posq] >= a) {
                            if(max1 < size[posq]) posar.clear(); 
                            posar.push_back(posq);
                            max1 = size[posq];
                        }
                    }
                }
            }
        }
    }
    /*int max1 = -1;
    vector<int> posar;
    for(int i = 0; i < n; i++) {
        if(size[i] >= a && size[i] <= b && max1 <= size[i]) {
            if(max1 < size[i]) posar.clear();
            posar.push_back(i);
            max1 = size[i];
        }
    }*/
    /*set<string> sss;
    for(int y : posar) {
        for(pair<string, int> x : pos) {
            if(x.second == y) sss.insert(x.first);
        }
    }
    if(sss.size() > 0) for(string x : sss) cout << x << endl;*/
    //for(int i = 0; i < n; i++) cout << parent[i] << " "; cout << endl;
    vector<string> sss;
    for(int y : posar) {
        for(pair<string, int> x : pos) {
            int p = find_parent(parent, x.second);
            if(p == y) sss.push_back(x.first);
        }
    }
    sort(sss.begin(), sss.end());
    if(sss.size() > 0) for(string abc : sss) cout << abc << endl;
    else cout << "no groups\n";
}

int main() {
    int n, m, a, b, f, s, t;
    cin >> n >> m >> a >> b >> f >> s >> t;
    membersInTheLargestGroups(n, m, a, b, f, s, t);
    return 0;
}
