#include <bits/stdc++.h>
using namespace std;
void nhaptennguoi(map<int, string>& nguoi, int n){
	for (int i = 1; i <= n; i++)
	{
		cout << "Ten nguoi thu " << i << " la ";
		string x; cin >> x;
		nguoi[i] = x;
	}
}
void FStatic(int F[], set<int> Res[], const map<int, string>& nguoi){
    for(int i = 0; F[i] != 0; i++)
	{
		cout << "\nF[" << i << "] co " << F[i] << " nguoi gom : ";
		for(auto z : Res[i]) cout << nguoi.at(z) << " ";
	}
}
void Add(){
}
void Del(){
}

void solve(){
	int n, m, u, v;
	cin >> n >> m;
	map<int, string> nguoi;
	nhaptennguoi(nguoi, n);
	vector<int> A[n + 5];
	set<int> Res[n + 5]; // cac vector rong
	queue<int> Q;
	while (m--)
	{
		cin >> u >> v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
	int F[n + 5]={}, d[n + 5];
	fill(d, d + n + 1, -1);

	cin >> F[0];
	for (int i = 1; i <= F[0]; i++)
	{
		cin >> u;
		d[u] = 0;
		Res[0].insert(u);
		Q.push(u);
	}
	while (!Q.empty()) // van hanh BFS
	{
		u = Q.front();
		Q.pop();

		for (int v : A[u])
		{
			if (d[v] == -1)
			{
				d[v] = d[u] + 1;
				Q.push(v);
				F[d[v]]++;
				Res[d[v]].insert(v);
			}
		}
	}
	FStatic(F, Res, nguoi);
}
int main()
{
	solve();
	return 0;
}
// 11 7
// Khanh Tuan Anh Dat Tuans David Alex Yasuo Hello Top1 Dinh
// 3 5
// 4 5
// 1 7
// 7 9
// 2 11
// 10 4
// 8 1
// 3
// 9 10 5