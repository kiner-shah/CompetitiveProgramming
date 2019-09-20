#include <iostream>
using namespace std;
typedef long long LL;
void villages_and_tribes() {
	int n;
	string s;
	cin>>n;
	while(n-- > 0) {
		cin>>s;
		bool flag = false;
		int counta = 0, countb = 0, l = s.length(), dots = 0;
		char last_encountered = '.';
		for(int i = 0; i < l; i++) {
		    if(s[i] == 'A') {
		        counta++;
		        if(flag && s[i] == last_encountered) { 
		        	counta += dots; dots = 0; 
		        	flag = false;
		        }
		        else if(flag) {
		        	dots = 0;
		    		flag = false;
		        }
		        last_encountered = 'A';
		    }
		    else if(s[i] == 'B') {
		        countb++;
		        if(flag && s[i] == last_encountered) { 
		        	countb += dots; dots = 0; 
		        	flag = false;
		        }
		        else if(flag) { dots = 0; flag = false; }
		        last_encountered = 'B';
		    }
		    else if(s[i] == '.') {
		        flag = true;
		        dots++;
		    }
		}
		cout<<counta<<" "<<countb<<endl;
	}
}
void periodic_palindrome_construction() {
	int t, p, n;
	cin>>t;
	while(t-- > 0) {
		cin>>n>>p;
		if(p == 1 && n >= 1) cout<<"impossible\n";
		else if(p == 2) cout<<"impossible\n";
		else {
			int val = p - 2;
			string temp = "a";
			for(int i = 0; i < val; i++) temp += 'b';
			if(val > 0) temp += 'a';
			
			int val1 = n / p;
			string final = "";
			for(int i = 0; i < val1; i++) final += temp;
			cout<<final<<endl;
		}
	}
}
typedef struct nn {
	LL data;
	struct nn *left;
	struct nn *right;
} node;
LL visited;
node * insertBST(node * root, LL value)
{
   node *q=root,*p,*r;
   //cout<<value<<" ";
   if(root==NULL) {
       root=(node*)malloc(sizeof(node));
       root->data=value; root->left=root->right=NULL;
       visited++;
   }
    else {
        while(q!=NULL) {
            p=q;
            visited++;
            if(q->data > value) q=q->left;
            else if(q->data<value) q=q->right;
        }
        if(p->data < value) {
            r=(node*)malloc(sizeof(node));
            r->data=value; r->left=r->right=NULL;
            p->right=r;
            visited++;
        }
        else {
            r=(node*)malloc(sizeof(node));
            r->data=value; r->left=r->right=NULL;
            p->left=r;
            visited++;
        }
    }
   return root;
}
void chef_goes_left_right_left() {
	int t; cin>>t;
	while(t-- > 0) {
		LL n, reziba;
		cin>>n>>reziba;
		LL x, i;
		
		node* root = NULL;
		for(i = 0; i < n; i++) {
			cin>>x;
			visited = 0;
			root = insertBST(root, x);
			//for(LL j : visited) cout<<j<<" "; cout<<endl;
			if(i == n - 1) {
				//cout<<visited.size()<<" "<<n<<endl;
				if(visited == n) {
					cout<<"YES\n";
				}
				else cout<<"NO\n";
			}
		}
	}
}
int main() {
	// villages_and_tribes();
	// periodic_palindrome_construction();
	// chef_goes_left_right_left();		// partially solved for 20 pts
	return 0;
}
