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
int f[N+10];
char s[N+10];

int find(int i){
	if (f[i]==i) return i;
	return f[i]=find(f[i]);
}

bool ok(int i, int j){
	if (i<0) return false;
	return (s[i]=='(' && s[j]==')') || (s[i]=='[' && s[j]==']');
}

bool isRight(int i){
	return s[i]==']' || s[i]==')';
}

bool isLeft(int i){
	return s[i]=='(' || s[i]=='[';
}


int main(){
	while (gets(s)!=NULL){
		n=strlen(s);
		if (n==0) continue;
		repf(i, 1, n-1){
			if (ok(i-1, i)) f[i]=i-1;
			else if (isLeft(i) && isRight(i-1) && f[i-1]!=i-1) f[i]=i-1;
			else if (isRight(i) && isRight(i-1) && f[i-1]!=i-1 && ok(find(i-1)-1, i)) f[i]=find(i-1)-1;
			else f[i]=i;
		}
		int k=-1;
		repf(i, 1, n-1) 
			if (isRight(i) && f[i]!=i && (k==-1 || i-find(i)>k-f[k]))
				k=i;
		if ((k!=-1) && isRight(k) && f[k]!=k){
			repf(i, f[k], k) putchar(s[i]);
		}
		printf("\n\n");

	}
	return 0;
}



