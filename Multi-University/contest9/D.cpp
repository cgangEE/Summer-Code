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
#define N 20

int i,j,k,m,n,l;
char s[N+10];
ll f[(1<<N)+10];
int bg, ed;

struct Q{
	int i, j;	//i: how many one ,j: value
	Q(){}
	Q(int i, int j):i(i),j(j){}
};

bool v[(1<<N)+10];

int main(){
	while (~scanf("%s", s)){
		n=strlen(s);
		queue<Q> q; clr(v, 0), clr(f, 0);
		q.push(Q(0,0)), v[0]=1, f[0]=1;

		while (q.size()){
			Q p=q.front(); q.pop();
			v[p.j]=0;
			if (p.i==n/2) continue;

			if (s[p.i]=='-') bg=0, ed=p.i-1;
			else bg=p.i+1, ed=n-1;

			cout<<p.i+1<<' '<<bg<<' '<<ed<<endl;

			repf(j, bg, ed) if ((p.j&(1<<j))==0){
				k=p.j|(1<<j);
				f[k]+=f[p.j];
				if (!v[k]) v[k]=1, q.push(Q(p.i+1, k));
			}
		}

		ll ans=0;

		if (s[n-1]=='+'){ puts(0); continue; }
		
		int ds=(1<<n)-1;
		q.push(), v[ds]=1, f[ds]=;
		while (q.size()){

			Q p=q.front(); q.pop();
			v[p.j]=0;



			repf(j, bg, ed) if ((p.j&(1<<j))==0){
				k=p.j^(1<<j);
				f[k]+=f[p.j];
				if (!v[k]) v[k]=1, q.push(Q(p.i-1, k));
			}
		}


		printf("%I64d\n", ans);
	}
	return 0;
}


