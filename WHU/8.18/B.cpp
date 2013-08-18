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
#define N 10000


int i,j,k,m,n,l,x;
char s[N+10];
bool inS[N+10];
int f[N+10];

int main(){
	int ts;
	scanf("%d", &ts);
	repf(te, 1, ts){
		scanf("%s", s);
		n=strlen(s);
		stack<int> stk;
		clr(inS, 0);
		clr(f, 0);
		rep(i, n) {
			if (stk.size() && stk.top()==s[i]){
				if (stk.size()>1) f[stk.top()]++;
			   	stk.pop();
			}
			else{
			   	if (stk.size())f[stk.top()]++;
				stk.push(s[i]);
			}
		}
		printf("Case %d\n", te);
		repf(i, 'A', 'Z') if (f[i]) printf("%c = %d\n", i, f[i]);
	}
	return 0;
}



