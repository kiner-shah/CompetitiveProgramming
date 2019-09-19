#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,x;
    scanf("%d",&n);
    while(n-- > 0) {
        scanf("%d",&x);
        if(x%2==0) printf("%d is even\n",x);
        else printf("%d is odd\n",x);
    }
    return 0;
}
