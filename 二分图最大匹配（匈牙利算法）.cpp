#include <iostream>
#include <cstring>
#define maxn 10005
using namespace std;

bool vis[maxn];
int paired[maxn], relat[maxn][maxn];
int n, m; //假设n表示右边的人，m表示左边的人
int ans;

bool find(int x) {//判断x（属于左边）能否匹配
	for(register int i = 1; i <= m; ++i) {
		if(relat[x][i] && !vis[i]) { //两者可以匹配并且i并没有尝试匹配过
			vis[i] = true;
			if(!paired[i] || find(paired[i])) {//可以直接匹配或者当前跟i匹配的可以换一换
				paired[i] = x;
				return true;
			}
		}
	}
	return false;
}

int solve() {
	memset(vis, false, sizeof(vis));
	for(register int i = 1; i <= n; ++i) {
		if(find(i))
			ans++;
	}
	return ans;
}