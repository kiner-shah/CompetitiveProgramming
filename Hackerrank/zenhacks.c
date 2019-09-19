#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void strange_grid_again() {
	long long int x,i,r,c,count=0,val,a[5]={0,2,4,6,8};
    scanf("%lld %lld",&r,&c);
    /*for(i=1;i<r;i++) {
        if(i%2==0)
            a[0]+=9;
        else
            a[0]+=1;
    } */
     x=(r-1)/2;
    if((r-1)%2==1) {
        a[0]+=1;
        a[0]=a[0]+10*x;
    }
    else {
       a[0]=a[0]+10*x;
    }
    val=a[0]+2*(c-1);
    printf("%lld",val);
}
void funny_string() {
	int t,i,j,k,flag=0; char a[10000],b[10000];
    scanf("%d",&t);
    for(i=0;i<t;i++) {
        scanf("%s",a);
        for(k=strlen(a)-1,j=0;j<strlen(a) && k>=0;j++,k--)
            b[j]=a[k];
        for(j=1;j<strlen(a);j++) {
            if(abs(a[j]-a[j-1])==abs(b[j]-b[j-1]))
                flag=1;
            else {
                flag=0; break;
            }
        }
        if(flag==1)
            printf("Funny\n");
        else
            printf("Not Funny\n");
    }
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    // strange_grid_again();
	// funny_string();
    return 0;
}
