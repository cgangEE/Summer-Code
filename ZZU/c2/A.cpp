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
#define N 100

int i,j,k,m,n,l;
char s[N+10], bg[N+10], ed[N+10];
char ans1[N+10], ans2[N+10];
int t1, t2;

int g(char *s){
	return (s[0]-'0')*10+s[1]-'0';
}

int gao(char *s){
	return g(s)*3600+g(s+3)*60+g(s+6);
}

int main(){
	int ts;
	scanf("%d", &ts);
	while (ts--){
		scanf("%d", &m);
		t1=t2=-1;
		while (m--){
			scanf("%s%s%s", s, bg, ed);
			int j=gao(bg), k=gao(ed);

			if (t1==-1 || j<t1)
				t1=j, memcpy(ans1, s, sizeof(s));
			if (t2==-1 || k>t2)
				t2=k, memcpy(ans2, s, sizeof(s));
			
		}
		printf("%s %s\n", ans1, ans2);
	}
	return 0;
}


