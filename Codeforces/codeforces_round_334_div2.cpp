#include <iostream>
#include <algorithm>
using namespace std;

void uncowed_forces() {
	int m[5];
    int w[5];
    int x[5]={500,1000,1500,2000,2500};
    int i,hs,hu;
    double score[5],sum=0.0,a,b;
    for(i=0;i<5;i++) cin>>m[i];
    for(i=0;i<5;i++) cin>>w[i];
    cin>>hs>>hu;
    for(i=0;i<5;i++) {
        a=0.3*x[i];// cout<<a<<" ";
        b=(1-(double)m[i]/250)*x[i] - 50*w[i]; //cout<<b<<endl;
        score[i]= a>b?a:b;
        sum+=score[i];
    }
    //cout<<sum<<endl;
    cout<<sum+100*hs-50*hu;
}
int main() {
    // your code goes here
    // uncowed_forces();
    return 0;
}
