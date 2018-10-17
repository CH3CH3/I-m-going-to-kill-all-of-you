#include <iostream>
#include <stdio.h>
#define maxn 100005
using namespace std;

struct node {
	int to, nxt, w;
}edge[maxn >> 1];
int head[maxn], cnt;
bool vis[maxn], flag;//(判断负环)

void add(int u, int v, int w) {
	edge[++cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].nxt = head[u];
	head[u] = cnt;
}

int n, m, s, dist[maxn];

void SPFA(int x) {
	vis[x] = true;
	for(register int i = head[x]; i; i = edge[i].nxt) {
		int v = edge[i].to;
		int w = edge[i].w;
		if(dist[v] > dist[x] + w) {
			dist[v] = dist[x] + w;
			if(vis[v]) {
				flag = true;
				break;
			}
			SPFA(v);;
		}
	}
}

int main() {
	cin >> n >> m >> s;
	int tmpa, tmpb, tmpc;
	for(register int i = 1; i <= m; ++i) {
		cin >> tmpa >> tmpb >> tmpc;
		add(tmpa, tmpb, tmpc);
	}
	for(register int i = 1; i <= n; ++i)
		dist[i] = 2147483647;
	dist[s] = 0;
	SPFA(s);
	for(register int i = 1; i <= n; ++i)
		cout << dist[i] << " ";
	cout << endl;
	return 0;
}