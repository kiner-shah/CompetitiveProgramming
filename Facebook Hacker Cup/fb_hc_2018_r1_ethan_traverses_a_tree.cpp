/* 
 * File:   ethan_traverses_a_tree.cpp
 * Author: Kiner Shah
 *
 * Created on 22 July, 2018, 15:05 PM
 */

#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;

typedef struct ST_SET_UN {
	int parent;
	int rank;
} SetUnion;

typedef struct NODE {
    int val;
    int left_ind;
    int right_ind;
} Node;

vector<int> pre_seq, post_seq;
SetUnion s[2001];
Node nodes[2001];

void preorder(int ind) {
    if(ind == -1) return;
    else {
        pre_seq.push_back(ind);
        preorder(nodes[ind].left_ind);
        preorder(nodes[ind].right_ind);
    }
}

void postorder(int ind) {
    if(ind == -1) return;
    else {
        postorder(nodes[ind].left_ind);
        postorder(nodes[ind].right_ind);
        post_seq.push_back(ind);
    }
}

int find_parent(int v) {
    if(s[v].parent == v) return v;
    else return find_parent(s[v].parent);
}

void union_set(int root1, int root2) {
//    int root1 = find_parent(u);
//    int root2 = find_parent(v);

    if(s[root1].rank > s[root2].rank) {
        s[root2].parent = root1;
    }
    else if(s[root1].rank < s[root2].rank) {
        s[root1].parent = root2;
    }
    else {
        s[root2].parent = root1;
        s[root1].rank++;
    }
}

int convertToLL3(string i) {
    std::stringstream ss;
    ss << i;
    LL x;
    ss >> x;
    return x;
}

//int main() {
//    ifstream in;
//    ofstream out;
//    in.open("input.in");
//    out.open("output.txt");
//    
//    string line;
//    getline(in, line);
//    int n, k, i = 0, t = (int) convertToLL3(line);
//    while(i < t) {
//        in >> n >> k;
//        for(int j = 0; j < n; j++) {
//            int l, r;
//            in >> l >> r;
//            
//            nodes[j].val = j;
//            nodes[j].left_ind = l - 1;
//            nodes[j].right_ind = r - 1;
//            
//            s[j].parent = j;
//            s[j].rank = 0;
//        }
//        
//        preorder(0);
//        postorder(0);
//        
////        for(int x : post_seq) cout << x << " "; cout << endl;
////        for(int x : pre_seq) cout << x << " "; cout << endl;
//        
//        for(int j = 0; j < n; j++) {
//            int parent_post = find_parent(post_seq[j]);
//            int parent_pre = find_parent(pre_seq[j]);
//            
//            if(parent_post != parent_pre) {
//                union_set(parent_post, parent_pre);
//            }
//        }
//        
////        for(int j = 0; j < n; j++) cout << find_parent(s[j].parent) << " "; cout << endl;
//        
//        map<int, int> k_mapping;
//        int jj = 1;
//        out << "Case #" << i + 1 << ": ";
//        bool used = false;
//        for(int j = 0; j < n; j++) {
//            int actual_par = find_parent(s[j].parent);
//            if(k_mapping.find(actual_par) == k_mapping.end()) {
//                if(jj == k) { used = true; }
//                k_mapping.insert(make_pair(actual_par, jj));
//                if(jj == k) jj = 1;
//                else jj++;
//            }
//        }
//        if(!used) out << "Impossible" << endl;
//        else {
//            for(int j = 0; j < n; j++)
//                out << k_mapping[find_parent(s[j].parent)] << " ";
//            out << endl;
//        }
//        post_seq.clear();
//        pre_seq.clear();
//        i++;
//    }
//    
//    in.close();
//    out.close();
//    return 0;
//}