#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef long long ll;
template <class T> void checkmax(T &t, T x){if (x > t) t = x;}
template <class T> void checkmin(T &t, T x){if (x < t) t = x;}
template <class T> void _checkmax(T &t, T x){if (t == -1 || x > t) t = x;}
template <class T> void _checkmin(T &t, T x){if (t == -1 || x < t) t = x;}
#define INF (INT_MAX/10)
#define SQR(x) ((x)*(x))
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define iter(v) __typeof((v).begin())
#define foreach(it, v) for (iter(v) it = (v).begin(); it != (v).end(); it++)
#define clr(ar,val) memset(ar, val, sizeof(ar))
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) a.begin(), a.end()
#define mid(x, y) ((x+y)/2)
#define vp vector<P>
#define itr iterator

char s[30], t[30];

struct P{
	int x, y, z, k;
	void update(){k=x*10000+y*100+z;}
	P(){}
	P(int x, int y, int z):x(x),y(y),z(z){
		update();
	}
	int gao(char *s){ return (s[0]-'0')*10+s[1]-'0'; }
	P(char *s){
		x=gao(s), y=gao(s+3), z=gao(s+6);
		update();
	}
	void add(){
		z++;
		if (z==60){
			z=0, y++;
			if (y==60){
				y=0, x++;
				if (x==24) x=0;
			}
		}
		update();
	}
	bool mod3(){ return (k%3==0); }
	bool operator <(const P&p)const{ return k<p.k; }
	bool operator <=(const P&p)const{ return k<=p.k; }
	bool operator >=(const P&p)const{ return k>=p.k; }
	bool operator >(const P&p)const{ return k>p.k; }
	bool operator ==(const P&p)const{ return k==p.k; }
	bool operator !=(const P&p)const{return k!=p.k; }
	void out(){
		cout<<x<<' '<<y<<' '<<z<<' '<<k<<endl;
	}
};

int i,j,k,m,n,l;
vp a;

int main(){
	P st(0,0,0), ed(0,0,0);
	do{
		if (st.mod3()) a.pb(st);
		st.add();
	}
	while (st!=ed);
	a.pb(P(100,0,0));
	sort(all(a));

	int tests;
	scanf("%d", &tests);
	while (tests--){
		scanf("%s%s", s, t);
		st=P(s), ed=P(t);
		int ans;
		if (st<=ed){
			j=lower_bound(all(a), st)-a.begin();
			k=upper_bound(all(a), ed)-a.begin();
			ans=k-j;
		}
		else{
			j=upper_bound(all(a), ed)-a.begin();
			k=lower_bound(all(a), P(100,0,0))-lower_bound(all(a), st);
			ans=k+j;
		}
		printf("%d\n", ans);
	}
	return 0;
}


