#include <iostream>
#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <ctime>

using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)

int i,j,k,m,n,l;
double v, d;
double pi=acos(-1.0);

int main(){
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w" ,stdout);
	int ts;
	scanf("%d", &ts);
	repf(te, 1, ts){
		scanf("%lf%lf", &v, &d);
		printf("Case #%d: %.9lf\n", te, asin(d*9.8/v/v)/2/pi*180);
	}
	return 0;
}
