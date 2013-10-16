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

double i,j,k,m,n,l;
char wk[][20]= {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int d[]={8, 8, 8, 8, 8, 4, 4};
char s[20];

#define eps 1e-9
int sgn(double d){
	return d<-eps?-1:d>eps;
}

void gao(){
	n-=(floor(n/48/k))*48*k;
	
	rep(j, 7) if (strcmp(wk[j], s)==0){
		repf(i, j, j+7){
		if (sgn(n)<=0){
		   	printf("%s\n", wk[(i-1+7)%7]);		
			break;
		}
		n-=d[i%7]*k;
	}
	}
}

int main(){
	while (~scanf("%s%lf%lf", s, &n, &k)){
		gao();
	}
	return 0;
}


