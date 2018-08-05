/*
ID: kiner.s1
LANG: C
TASK: beads
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int max(int i, int j) {
	return i>j?i:j;
}

int main() {
	FILE *p1,*p2;
	int n,i,len,l[701][2],r[701][2],j,max1=0;
	char *s,*d;
	p1=fopen("beads.in","r");
	p2=fopen("beads.out","w");
	fscanf(p1,"%d",&n);
	s=(char *)malloc(n+1);
	fscanf(p1,"%s",s);
	d=(char *)malloc(strlen(s)+strlen(s)+1);
	strcpy(d,s);
	strcat(d,s);
 	len=strlen(d);
 	l[0][0]=0; l[0][1]=0;
 	r[len][0]=0; r[len][1]=0;
 	for(i=1;i<len;i++) {
 		if(d[i-1] == 'r') { l[i][0]=l[i-1][0] + 1; l[i][1]=0; }
 		else if(d[i-1] == 'b') { l[i][0]=0; l[i][1]=l[i-1][1] + 1; }
 		else if(d[i-1] == 'w') { l[i][0]=l[i-1][0] + 1; l[i][1]=l[i-1][1] + 1; }
 	}
 	for(i=len-1;i>=0;i--) {
 		if(d[i] == 'r') { r[i][0]=r[i+1][0]+1; r[i][1]=0; }
 		else if(d[i] == 'b') { r[i][0]=0; r[i][1]=r[i+1][1]+1; }
 		else if(d[i] == 'w') { r[i][0]=r[i+1][0]+1; r[i][1]=r[i+1][1]+1; }
 	}
 	for(i=0;i<len;i++) {
 		max1=max(max1, max(l[i][0],l[i][1]) + max(r[i][0],r[i][1]));
 	}
 	//if(max1 > len) max1=len;
 	//fprintf(p2,"%s\n",d);
 	fprintf(p2,"%d\n",(max1 > n ? n : max1));
	return 0;
}