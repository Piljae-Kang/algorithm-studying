#include <bits/stdc++.h>
using namespace std;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int bfs(const vector<vector<int>>& mat, vector<vector<int>>& visited, int sx, int sy, int n, int m) {
    queue<pair<int,int>> q;
    q.push({sx, sy});
    visited[sx][sy] = 1;              // 시작점 방문 표시
    int area = 1;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (mat[nx][ny] == 1 && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
                ++area;
            }
        }
    }
    return area;
}

int main() {
    fast_io();

    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> mat[i][j];

    vector<vector<int>> visited(n, vector<int>(m, 0));

    int cnt = 0;
    int max_area = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 1 && !visited[i][j]) {
                int area = bfs(mat, visited, i, j, n, m);
                ++cnt;
                if (area > max_area) max_area = area;
            }
        }
    }

    cout << cnt << "\n" << max_area << "\n";
    return 0;
}