struct DSU {
  vector<vector<pair<int, int>>> par;
  int time = 0; // initial time
  DSU(int n) : par(n + 1, {{-1, 0}}) {}

  bool merge(int u, int v) {
    ++time;
    if ((u = root(u, time)) == (v = root(v, time))) return 0;
    if (par[u].back().first > par[v].back().first)
      swap(u, v);
    par[u].emplace_back(par[u].back().first + par[v].back().first, time);
    par[v].emplace_back(u, time); //par[v] = u
    return 1;
  }

  bool same(int u, int v, int t) {
    return root(u, t) == root(v, t);
  }

  int root(int u, int t) {
    if (par[u].back().first >= 0 && par[u].back().second <= t)
      return root(par[u].back().first, t);
    return u;
  }

  int size(int u, int t) { //size of the component of u at time t
    u = root(u, t);
    int l = 0, r = (int) par[u].size() - 1, ans = 0;
    while (l <= r) {
      int mid = l + r >> 1;
      if (par[u][mid].second <= t) ans = mid, l = mid + 1;
      else r = mid - 1;
    }
    return -par[u][ans].first;
  }

  int first_time_to_be_same(int u, int v) {
    int ans = -1, l = 0, r = time;
    while (l <= r) {
      int mid = l + r >> 1;
      if (same(u, v, mid)) ans = mid, r = mid - 1;
      else l = mid + 1;
    }
    return ans;
  }
};
