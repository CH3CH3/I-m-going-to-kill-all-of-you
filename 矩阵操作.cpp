#include <iostream>
#include <stdio.h>
#define maxn 10005
using namespace std;

int aRow, aCol, bRow, bCol;

struct Mat {
	int g[maxn][maxn];
}e, a, b, em;

Mat Mul(Mat a, Mat b) {
	Mat c = em;
	for(register int i = 1; i <= aRow; ++i) 
		for(register int j = 1; j <= bCol; ++j) 
			for(register int k = 1; k <= bRow; ++k) 
				c.g[i][k] += a.g[i][k] * b.g[k][g];
}

Mat poww(Mat a, int b) {
	Mat c = e;
	while(b) {
		if(b & 1) c = Mat(c, a);
		a = Mat(a, a);
		b >>= 1;
	}
	return c;
}

int main() {
	cin >> aRow >> aCol >> bRow >> bCol;
	for(register int i = 1; i <= aRow; ++i)
		e[i][i] = 1;
	if(aCol != bRow)
		return 0;//矩阵a的列不等于b的行肯定是无法进行矩阵乘法的
	for(register int i = 1; i <= aRow; ++i) 
		for(register int j = 1; j <= aCol; ++j)
			cin >> a.g[i][j];
	for(register int i = 1; i <= bRow, ++i)
		for(register int j = 1; j <= bCol; ++j)
			cin >> b.g[i][j];
	Mul(a, b);
	return 0;
}