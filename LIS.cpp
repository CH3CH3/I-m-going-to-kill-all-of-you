#include <iostream>
#include <stdio.h>
#include <algorithm>
#define maxn 100005
using namespace std;

int a[maxn], b[maxn];//a数组表示原本的数组，b则表示排序时用的数组
int c[maxn];
int n; 

int main() {
	cin >> n;
	for(register int i = 1; i <= n; ++i)
		cin >> a[i];
	int top = 1;
	b[1] = a[1];
	for(register int i = 2; i <= n; ++i) {
		if(a[i] >= b[top])
			b[++top] = a[i];
		else {
			int posi = upper_bound(b + 1, b + 1 + top, a[i]) - b;
			b[posi] = a[i];
		}
	}//非严格
	c[1] = a[1];
	int ind = 1;
	for(register int i = 2; i <= n; ++i) {
		if(a[i] > c[ind])
			c[++ind] = a[i];
		else {
			int posi = lower_bound(c + 1, c + 1 + top, a[i]) - c;
			c[posi] = a[i];
		}
	} //严格
	cout << top << endl;
	cout << ind << endl;
	return 0;
}