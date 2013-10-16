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

struct P{
	int x, y;
	P(){}
	P(int x, int y):x(x),y(y){}
	void in(){ scanf("%d%d", &x, &y); }

	P operator -(const P&p)const{
		return P(x-p.x, y-p.y); 
	}
	bool operator <(const P&p)const{
		if (abs(x)!=abs(p.x)) return abs(x)<abs(p.x);
		return abs(y)<abs(p.y);
	}
	bool operator ==(const P&p)const{
		return x==p.x && y==p.y;
	}
};

int i,j,k,m,n,l;
P a[N+10];
char d[4]={'R', 'L', 'U', 'D'};
P dd[]={P(1, 0), P(-1, 0), P(0, 1), P(0, -1)};


void gao(P x, P y){
	P a=y-x;
	if (a.x){
		printf("1 %d %c\n", abs(a.x), a.x>0?'R':'L');
	}
	if (a.y){
		printf("1 %d %c\n", abs(a.y), a.y>0?'U':'D');
	}
}

int main(){
	while (~scanf("%d", &n)){
		k=0;
		rep(i, n){
		   	a[i].in();
			if (a[i].x==0 || a[i].y==0) k+=4;
			else k+=6;
		}
		sort(a, a+n);
		printf("%d\n", k);	
		P src(0,0);
		rep(i, n){
			gao(src, a[i]);
			puts("2");
			gao(a[i], src);
			puts("3");
		}
	}
	return 0;
}
