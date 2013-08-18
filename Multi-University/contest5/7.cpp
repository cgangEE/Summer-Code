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
#define N 200

int i,j,k,m,n,l;
int a[N+10];
char o[N+10];
double p[N+10];

int main(){
	int te=0;
	while (~scanf("%d", &n)){
		repf(i, 0, n) scanf("%d", &a[i]);
		repf(i, 1, n){
			o[i]=getchar();
			while (strchr("&|^", o[i])==NULL) o[i]=getchar();
		}
		repf(i, 1, n) scanf("%lf", &p[i]);


		double ret=0;
		double x[2][2];
		rep(I, 20){
			int i=1<<I;

			clr(x, 0);
			x[0][ (a[0]&i)?1:0 ] =1;

			repf(j, 1, n){
				clr(x[j%2], 0);
				int w=(a[j]&i)?1:0;
				rep(k, 2){
					if (o[j]=='&') l=k&w;
					else if (o[j]=='|') l=k|w;
					else l=k^w;

					x[j%2][l]+=x[1-j%2][k]*(1-p[j]);
					x[j%2][k]+=x[1-j%2][k] * p[j];
				}
				if (j==n) ret+=i * x[j%2][1];
			}

		}
		printf("Case %d:\n", ++te);
		printf("%.6lf\n", ret);
	}
	return 0;
}


