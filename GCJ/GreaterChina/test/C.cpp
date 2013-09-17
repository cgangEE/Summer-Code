#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))

#define N 100

int i,j,k,m,n,l;
char s[N+10][200];

int main(){
	freopen("C-small-2-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int ts;
	scanf("%d\n", &ts);
	repf(te, 1, ts){
		scanf("%d\n", &n);
		repf(i, 1, n) gets(s[i]);
		int ret=0;
		repf(i, 2, n){
			if (strcmp(s[i], s[1])<0) ret++;
			else memcpy(s[1], s[i], sizeof(s[i]));
		}
		printf("Case #%d: %d\n", te, ret);
	}
	return 0;
}

