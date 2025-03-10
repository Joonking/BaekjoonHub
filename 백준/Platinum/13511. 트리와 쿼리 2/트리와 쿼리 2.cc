#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

vector<p> g[101010];
ll dp[101010][22];
ll dist[101010];
ll dep[101010];
ll n;
bool chk[101010];

void dfs(ll now, ll d, ll c) {
	chk[now] = 1;
	dep[now] = d;
	dist[now] = c;
	for (auto i : g[now]) {
		ll nxt = i.first;
		if (chk[nxt]) continue;
		ll nxtCost = i.second + c;
		dp[nxt][0] = now;
		dfs(nxt, d + 1, nxtCost);
	}
}

void make() {
	for (int j = 1; j < 22; j++) {
		for (int i = 1; i <= n; i++) {
			dp[i][j] = dp[dp[i][j - 1]][j - 1];
		}
	}
}

ll getLca(ll u, ll v) {
	if (dep[u] > dep[v]) swap(u, v);
	ll diff = dep[v] - dep[u];
	for (int i = 0; diff; i++) {
		if (diff & 1) v = dp[v][i];
		diff >>= 1;
	}
	if (u == v) return u;
	for (int i = 21; i >= 0; i--) {
		if (dp[u][i] != dp[v][i]) u = dp[u][i], v = dp[v][i];
	}
	return dp[u][0];
}

ll getDist(ll u, ll v) {
	ll lca = getLca(u, v);
	return dist[u] + dist[v] - 2 * dist[lca];
}

ll getkth(ll u, ll v, ll k) {
	ll lca = getLca(u, v);
	ll diff = dep[u] - dep[lca];
	k--;
	if (diff >= k) {
		for (int i = 0; k; i++) {
			if (k & 1) u = dp[u][i];
			k >>= 1;
		}
		return u;
	}

	k = dep[v] - dep[lca] + diff - k;
	for (int i = 0; k; i++) {
		if (k & 1) v = dp[v][i];
		k >>= 1;
	}
	return v;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		ll s, e, x; cin >> s >> e >> x;
		g[s].push_back({ e, x });
		g[e].push_back({ s, x });
	}
	dfs(1, 1, 0); make();

	int m; cin >> m;
	while (m--) {
		int op; cin >> op;
		if (op == 1) {
			ll a, b; cin >> a >> b;
			cout << getDist(a, b) << "\n";
		}
		else {
			ll a, b, c; cin >> a >> b >> c;
			cout << getkth(a, b, c) << "\n";

		}
	}
}