#include <iostream>
#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)

int i,j,k,m,n,l;
char s[1000];

int main(){
	int ts;
	scanf("%d", &ts);
	repf(te, 1, ts){
		scanf("%s", s);
		n=strlen(s);
		printf("Case #%d: ", te);
		if (n>=4 && (strcmp(s+n-4, "desu")==0)){
			s[n-4]=0;
		}
			printf("%snanodesu\n", s);
	}
	return 0;
}


