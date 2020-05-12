#include<map>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<string>
#include<cstdio>
#include <iomanip>
using namespace std;
const int maxn = 3e5 + 10;
#define ll long long
int i, j, k;
int n, m, q;
const int inf = 0x3f3f3f;
const int mod = 1e9 + 7;
map<ll, ll> mpp[30];
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}
const int maxm = 100;
struct node {
	int cost, ddl;
	int begin, end;
} a[maxm];
bool operator<(const node& a, const node& b) {
	return a.ddl < b.ddl;
}
int main() {
	cin >> n;//任务是数量
	for (i = 0; i < n; i++) {
		cin >> a[i].cost;
	}
	for (i = 0; i < n; i++) {
		cin >> a[i].ddl;
	}
	//每个任务的耗费时间和deadline
	sort(a, a + n);
	int maxx = 0, begin = 0;
	for (i = 0; i < n; i++) {
		a[i].begin = begin;
		a[i].end = begin + a[i].cost;
		begin += a[i].cost;
		maxx = max(maxx, a[i].end - a[i].ddl);
	}

	cout << maxx << endl;
	return 0;
}
/*
dispatch
5
5 3 8 10 4
10 20 12 11 15
*/
