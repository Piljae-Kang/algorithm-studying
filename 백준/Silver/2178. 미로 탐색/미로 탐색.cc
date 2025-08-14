#include <bits/stdc++.h>

void fast_io() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); 
    std::cout.tie(NULL);
}

const int DIRS[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int bfs(std::vector<std::vector<int>>& mat, std::vector<std::vector<int>>& vis, std::pair<int, int> start, std::pair<int, int> end) {
    int h = mat.size(); 
    int w = mat[0].size();
    
    std::queue<std::pair<int, int>> q;
    std::queue<int> dist_q;  // 거리 저장용 큐
    
    q.push(start);
    dist_q.push(1);  // 시작점 거리 1
    vis[start.first][start.second] = 1;
    
    while (!q.empty()) {
        int u = q.front().first;
        int v = q.front().second;
        int count = dist_q.front();
        
        q.pop();
        dist_q.pop();
        
        // 목적지 도달
        if (u == end.first && v == end.second) {
            return count;
        }
        
        // 4방향 탐색
        for (int i = 0; i < 4; i++) {
            int new_u = u + DIRS[i][0];
            int new_v = v + DIRS[i][1];
            
            // 범위 체크
            if (new_u < 0 || new_v < 0 || new_u >= h || new_v >= w) continue;
            
            // 벽이 아니고 방문하지 않은 곳
            if (mat[new_u][new_v] == 1 && vis[new_u][new_v] == 0) {
                vis[new_u][new_v] = 1;
                q.push({new_u, new_v});
                dist_q.push(count + 1);
            }
        }
    }
    
    return -1;  // 경로를 찾을 수 없음
}

int main(){
    fast_io();

    int n, m;

    std::cin >> n >> m;

    std::vector<std::vector<int>> mat(n, std::vector<int>(m));
    std::vector<std::vector<int>> vis(n, std::vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        std::string line;
        std::cin >> line;
        
        for (int j = 0; j < m; j++) {
            mat[i][j] = line[j] - '0';
        }
    }

    int result = bfs(mat, vis, {0, 0}, {n-1, m-1});
    
    if (result == -1) {
        std::cout << "경로를 찾을 수 없습니다.\n";
    } else {
        std::cout << result << "\n";
    }

    return 0;
}