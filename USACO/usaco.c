/*
ID: kiner.s1
LANG: C
TASK: gift1
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node {
	char name[20];
	int val;
} GIFT;

int find(GIFT *g, int n, char name[]) {
	int i;
	for(i=0;i<n;i++) {
		if(strcmp(g[i].name,name) == 0)
			return i;
	}
	return -1;
}

int main() {
	int n,amt,np,divided,i;
	char per[20],b[20];
	GIFT *g;
	FILE *p1=fopen("gift1.in","r");
	FILE *p2=fopen("gift1.out","w");
	fscanf(p1,"%d",&n);
	g=(GIFT *) malloc(sizeof(n));
	for(i=0;i<n;i++) {
		fscanf(p1,"%s",g[i].name);
		g[i].val=0;
	}
	for(i=0;i<n;i++) {
		fscanf(p1,"%s",b);
		fscanf(p1,"%d",&amt);
		fscanf(p1,"%d",&np);
		if(np) {
			divided=amt/np;
			g[find(g,n,b)].val -= (divided * np);
			while(np--) {
				fscanf(p1,"%s",per);
				g[find(g,n,per)].val += divided;
			}
 		}
	}
	for(i=0;i<n;i++) {
		fprintf(p2,"%s %d\n",g[i].name,g[i].val);
	}
	return 0;
}