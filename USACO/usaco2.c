/*
ID: kiner.s1
LANG: C
TASK: milk2
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct node {
	int s,f;
}FEED;

int comp(const void *a, const void *b) {
	return ((FEED*)a)->s > ((FEED*)b)->s;
}

int max(int i, int j) {
	return i>j?i:j;
}

int main() {
	FILE *p1,*p2;
	int n,i,j,maxfedsofar,maxnotfedsofar=0,start,finish;
	FEED *ff;
	p1=fopen("milk2.in","r");
	p2=fopen("milk2.out","w");
	fscanf(p1,"%d",&n);
	ff=(FEED *)malloc(n*sizeof(FEED));
	for(i=0;i<n;i++) {
		fscanf(p1,"%d %d",&ff[i].s,&ff[i].f);
	}
	qsort(ff,n,sizeof(FEED),comp);
	start=ff[0].s; finish=ff[0].f;
	maxfedsofar=ff[0].f-ff[0].s;
	for(i=1;i<n;i++) {
		if(ff[i].s <= finish) {
			if(ff[i].s <= start) start=ff[i].s;
			if(ff[i].f >= finish) finish=ff[i].f;
		}
		else {
			maxfedsofar=max(maxfedsofar,finish-start);
			maxnotfedsofar=max(maxnotfedsofar,ff[i].s-finish);
			start=ff[i].s; finish=ff[i].f;
		}
	}
	fprintf(p2,"%d %d\n",maxfedsofar,maxnotfedsofar);
	return 0;
}