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
#define N 100000 

int i,j,k,m,n,l;
char a[N+10], b[N+10], c[N+10];
int f[N+10], len[N+10];
int next[N+10];

void getFail(){
	next[0]=next[1]=0;
	int j;
	repf(i, 1, k-1){
		j=next[i];
		while (j && c[i]!=c[j]) j=next[j];
		next[i+1]= c[i]==c[j]?j+1:0;
	}
}

int find(int u){
	int j=0;
	for (int i=u; i<n; ++i){
		while (j&& c[j]!=a[i]) j=next[j];
		if (c[j]==a[i]) ++j;
		if (j==k) return i-k+1;
	}
	return -1;
}

int main(){
	gets(a), gets(b);
	n=strlen(a), m=strlen(b);
	k=0;

	int w=0;
	clr(f, -1);
	
	rep(i, m+1){
	if (i==m || b[i]==' '){
		c[k]=0;
		len[w]=strlen(c);
		j=0;
		int u=(w==0?0:f[w-1]+len[w-1]+1);

		getFail();

		f[w]=find(u);


		k=0;
		if (f[w]==-1){
			puts("I HAVE FAILED!!!");
			return 0;
		}
		w++;
	}
	else{
		c[k]=b[i];
		k++;
	}
	}
	
	f[w]=INT_MAX;
	k=0;
	rep(i, n){
		if (i<f[k]){
		  if (a[i]!=' ')  	a[i]='_';
		}
		else{
			i+=len[k]-1;
			k++;
		}	
	}
	puts(a);
	return 0;
}


