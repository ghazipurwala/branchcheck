#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll maxnoeds = 1e5 + 1;
#define INF 1e18 + 2
#define fo(i, a, b) for (ll i = a; i < b; i++)
#define pb push_back
#define po pop_back
#define pii pair<ll,ll>
// #define v vector<ll>
#define code_fast                     \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);

vector<pair<ll, ll>> adj[maxnoeds];
vector<bool> visited(maxnoeds, false);
void recoverpath()
{
}

void djikstra(ll start, ll end, ll nodes)
{
	vector<ll> distance(nodes + 1, INF);
	priority_queue<pair<ll, ll>,vector<pii>, greater<pii>> temp;
	distance[start] = 0;
	temp.push({0,start});
	vector<int> prev(nodes, -1);
	prev[0] = 0;
	while (!temp.empty())
	{
		pair<ll, ll> elem = temp.top();
		ll index = elem.second;
		ll minval = elem.first;
		visited[index] = true;
		temp.pop();
		if (distance[index] < minval)
		{
			continue;
		}
		for (auto k : adj[index])
		{
			if (visited[k.first])
			{
				continue;
			}
			ll newdist = distance[index] + k.second;
			if (newdist < distance[k.first])
			{
				prev[k.first] = index;
				distance[k.first] = newdist;
				temp.push({newdist,k.first});
			}
		}
		if (index == end)
		{
			break;
		}
	}
	vector<int> result;

	if (distance[end] != INF)
	{
		for (ll v = end; v != start; v = prev[v])
		{
			result.push_back(v);
		}
		result.push_back(start);
		reverse(result.begin(), result.end());
		for (auto k : result)
		{
			cout << k + 1 << " ";
		}
	}
	else
	{
		cout << -1 << "\n";
	}
}

int main()
{
	code_fast ll n, m;
	cin >> n >> m;
	for (ll i = 0; i < m; i++)
	{
		ll from, to, weight;
		cin >> from >> to >> weight;
		adj[from - 1].push_back(make_pair(to - 1, weight));
		adj[to - 1].push_back(make_pair(from - 1, weight));
	}
	djikstra(0, n - 1, n);

	return 0;
}