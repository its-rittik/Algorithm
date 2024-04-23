#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int n;
vector<int> u, v, p, way;
int hungarian(vector<int>& assignment, vector<vector<int>>& matrix) {
  for (int i = 1; i <= n; ++i) {
    p[0] = i;
    int j0 = 0;
    vector<int> minv(n + 1, INF);
    vector<bool> used(n + 1, false);
    do {
      used[j0] = true;
      int i0 = p[j0], delta = INF, j1;
      for (int j = 1; j <= n; ++j) {
        if (!used[j]) {
          int cur = matrix[i0 - 1][j - 1] - u[i0] - v[j];
          if (cur < minv[j]) {
            minv[j] = cur;
            way[j] = j0;
          }
          if (minv[j] < delta) {
            delta = minv[j];
            j1 = j;
          }
        }
      }
      for (int j = 0; j <= n; ++j) {
        if (used[j]) {
          u[p[j]] += delta;
          v[j] -= delta;
        } else {
          minv[j] -= delta;
        }
      }
      j0 = j1;
    } while (p[j0] != 0);
    do {
      int j1 = way[j0];
      p[j0] = p[j1];
      j0 = j1;
    } while (j0 != 0);
  }
  int totalCost = -v[0];
  for (int j = 1; j <= n; ++j) {
    assignment[p[j] - 1] = j - 1;
  }
  return totalCost;
}

int main() {
  vector<vector<int>> matrix;
  cin >> n;
  for (int i = 0; i < n; i++) {
    vector<int> w(n);
    for (int j = 0; j < n; j++) {
      cin >> w[j];
    }
    matrix.push_back(w);
  }
  u.resize(n + 1);
  v.resize(n + 1);
  p.resize(n + 1);
  way.resize(n + 1);
  vector<int> assignment(n);
  int result = hungarian(assignment, matrix);
  cout << result << '\n';
  for (int i = 0; i < n; ++i) {
    cout << i + 1 << " " << assignment[i] + 1 << endl;
  }
  return 0;
}
