#include <iostream>
#include <queue>
#define maxn 50005
using namespace std;

queue<int> Lily;
int n, m;

struct node {
	int to, nxt, w;
}edge[maxn >> 1];
int head[maxn], cnt, dist[maxn];
bool vis[maxn];

void add(int u, int v, int w) {
	edge[++cnt].to = v;
	edge[cnt].w = w;
	edge[cnt].nxt = head[u];
	head[u] = cnt;
}

void SPFA(int s) {
	for(register int i = 1; i <= n; ++i)
		dist[i] = 2147483647;
	dist[s] = 0;
	vis[s] = true;
	Lily.push(s);
	while(!Lily.empty()) {
		int f = Lily.front();
		Lily.pop();
		vis[f] = false;
		for(register int i = head[f]; i; i = edge[i].nxt) {
			int v = edge[i].to;
			int w = edge[i].w;
			if(dist[v] > dist[f] + w){
				dist[v] = dist[f] + w;
				if(!vis[v])
					Lily.push(v);
			}
		}
	}
}

int main() {
	cin >> n >> m;
	int tmpa, tmpb, tmpc;
	for(register int i = 1; i <= m; ++i) {
		cin >> tmpa >> tmpb >> tmpc;
		add(tmpa, tmpb, tmpc);
	}
	SPFA(1);
	cout << dist[n] << endl;
	return 0;
}