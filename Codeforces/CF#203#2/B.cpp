#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define sz(a) ((int)(a).size())
#define pb push_back

#define N 100000

int i,j,k,m,n,l;
int tp[N+10], a[N+10], c[N+10];
int d[N+10], s[N+10];

int gao(int i){
	int ret=0;
	while (i && c[i]<=1){
		ret++;
		i=a[i];
	}
	return ret;
}

void out(int i){
	s[0]=0;
	while (i && c[i]<=1){
		s[++s[0]]=i;
		i=a[i];
	}
	repd(i, s[0], 1){
		if (i!=s[0]) putchar(' ');
		printf("%d", s[i]);
	}
	putchar('\n');
}

int main(){
	while (~scanf("%d", &n)){
		clr(c, 0);
		repf(i, 1, n) scanf("%d", &tp[i]);
		repf(i, 1, n) scanf("%d", &a[i]), c[a[i]]++;

		int k=-1;
		repf(i, 1, n) if (tp[i]==1){
			d[i]=gao(i);
			if (k==-1 || d[i]>d[k]) k=i;
		}
		printf("%d\n", d[k]);
		out(k);
	}
	return 0;
}
