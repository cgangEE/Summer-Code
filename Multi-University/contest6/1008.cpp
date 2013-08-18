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
#define N 1000000
#define M N*3

int i,j,k,m,n,l;
char s[N+10];
bool f[M*2+10];

void init(){
	queue<int> q; 
	clr(f, 0);

	f[1]=1, q.push(1);
	while (q.size()){
		i=q.front();
		q.pop();
		if (i*2<=M && !f[i*2])
			f[i*2]=1, q.push(i*2);
		if (i-6>=0 && !f[i-6])
			f[i-6]=1, q.push(i-6);
	}
}

bool solve(){
	n=strlen(s);
	if (s[0]!='M') return false;
	k=0;
	repf(i, 1, n-1)
		if (s[i]=='I') k++;
		else if (s[i]=='U') k+=3;
		else return false;
	return f[k];
}

int main(){
	init();
	int tests;
	scanf("%d", &tests);
	while (tests--){
		scanf("%s", s);
		puts(solve()?"Yes":"No");
	}
	return 0;
}


