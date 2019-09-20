#include <stdio.h>

int main(void) {
	// your code goes here
	char a[101]; int i,n;
	scanf("%d",&n);
	gets(a);
	while(n-- > 0) {
		gets(a);
		for(i=0;a[i]!='\0';i++) {
			if((a[i]>='a' && a[i]<='y') || (a[i]>='A' && a[i]<='Y'))
				printf("%c",a[i]+1);
			else if(a[i]=='z')
				printf("a");
			else if(a[i]=='Z')
				printf("A");
		}
		printf("\n");
		//puts(a);
	}
	return 0;
}
