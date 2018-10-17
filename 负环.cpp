#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
#define maxn 100005
using namespace std;

struct node {
	int to, nxt, w;
}edge[maxn >> 1];
int head[maxn], cnt, appCount[maxn];
bool vis[maxn], flag;

void add(int u, int v, int w) {
	edge[++cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].nxt = head[u];
	head[u] = cnt;
}

int n, m, s, dist[maxn], t;

void SPFA(int s) {
	queue<int> Lily;
	for(register int i = 1; i <= n; ++i)
		dist[i] = 2147483647;
	memset(vis, false, sizeof(vis));
	dist[s] = 0;
	Lily.push(s);
	vis[s] = true;
	appCount[s] = 1;
	while(!Lily.empty()) {
		int f = Lily.front();
		Lily.pop();
		vis[f] = false;
		for(register int i = head[f]; i; i = edge[i].nxt) {
			int v = edge[i].to;
			int w = edge[i].w;
			if(dist[v] > dist[f] + w) {
				dist[v] = dist[f] + w;
				appCount[v] = appCount[f] + 1;
				if(appCount[v] > n) {
					flag = true;
					return;
				}
				if(!vis[v]) 
					Lily.push(v);
			}
		}
	}
}

void solve() {
	memset(head, 0, sizeof(head));
	memset(vis, false, sizeof(vis));
	memset(appCount, 0, sizeof(appCount));
	flag = false;
	cnt = 0;
	cin >> n >> m;
	int tmpa, tmpb, tmpc;
	for(register int i = 1; i <= m; ++i) {
		cin >> tmpa >> tmpb >> tmpc;
		add(tmpa, tmpb, tmpc);
		if(tmpc >= 0)
			add(tmpb, tmpa, tmpc);
	}
	SPFA(1);
	if(flag) cout << "YE5" << endl;
	else cout << "N0" << endl;
	return;
}

int main() {
	cin >> t;
	memset(head, 0, sizeof(head));
	memset(vis, false, sizeof(vis));
	memset(appCount, 0, sizeof(appCount));
	cnt = 0;
	while(t--) solve();
	return 0;
}