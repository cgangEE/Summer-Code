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
#define N 100

int i,j,k,m,n,l;
int a[N+10], b[N+10];

int main(){
	while (~scanf("%d%d", &n, &m)){
		rep(i, n) scanf("%d", &a[i]);
		rep(i, m) scanf("%d", &b[i]);
		sort(a, a+n), sort(b, b+m);
		int x=max(a[n-1], a[0]*2);
		int y=b[0]-1;
		if (x<=y)
			cout<<x<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}
