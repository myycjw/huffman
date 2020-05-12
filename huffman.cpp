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
int w[100];
class node {
	public:
		char elem, s;
		int w;
		node* parent,* left,* right;
		node();
		bool operator < (const node &m)const {
			return w < m.w;
		}
};
node::node() {
	this->s = ' ';
	this->elem = '*';
	this->parent = this->left = this->right = NULL;
}
void code(node & tree) {
	if (tree.left == NULL && tree.right == NULL) { 
		string s;
		node temp = tree;
		while (temp.parent != NULL) {
			s = temp.s + s;
			temp = *temp.parent;
		}
		cout << tree.elem << "µÄ¹þ·òÂü±àÂëÊÇ£º" << s << endl;
		return;
	}
	//×ÓÊ÷
	code(*tree.left);
	code(*tree.right);
}
int main() {
	string str;
	while (1) {
		cout << "ÇëÊäÈëÒ»´®×Ö·û£º" << endl;
		cin >> str;
		char c[100];
		n = str.length();
		int cnt = 0, time;
		for (i = 0; i < n; i++) {
			j = 0; time = 0;
			while (str[i] != str[j])
				j++;
			if (j == i) {
				c[cnt] = str[i];
				cout << "×Ö·û" << c[cnt] << "³öÏÖ";
			}
			else {
				continue;
			}

			for (j = i; j < n; j++)
				if (str[i] == str[j])
					time++;
			cout << time << "´Î" << endl;
			w[cnt] = time;
			cnt++;
		}
		node t;
		vector<node>q;
		for (i = 0; i < cnt; i++) {
			t.elem = c[i];
			t.w = w[i];
			q.push_back(t);
		}

		int index = 0;
		sort(q.begin(), q.end());
		while (q.size() < 2 * cnt - 1) {
			t.w = q[index].w + q[index + 1].w;
			q[index].s = '0';
			q[index + 1].s = '1';
			t.elem = '*';
			q.push_back(t);
			sort(q.begin(), q.end());
			index += 2;
		}
		int now = 0;
		while (now + 2 < 2 * cnt) {
			for (j = now + 1; j <= q.size(); j++) {
				if (q[j].elem == '*' && q[j].left == NULL && (q[j].w == q[now].w + q[now + 1].w)) {
					q[j].left = &q[now];
					q[j].right = &q[now + 1];
					q[now].parent = q[now + 1].parent = &q[j];
					break;
				}
			}
			now += 2;
		}
		t = q.back();
		code(t);
		puts("");
	}
	return 0;
}
/*
any string without string.
*/
