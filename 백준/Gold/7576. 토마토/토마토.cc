#include<bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<vector<int>> my_move = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<vector<int>> vis;


int bfs (vector<pair<int, int>>& start_pos, vector<vector<int>>& mat){

    queue<pair<int, int>> q;

    for (pair<int, int> pr : start_pos){

        q.push(pr);

        vis[pr.first][pr.second] = 0;
    }

    int max_value = -1;

    int h = mat.size();
    int w = mat[0].size();

    while(!q.empty()){

        pair<int, int> cur_pos = q.front();

        q.pop();

        for (int i=0; i<4; i++){

            int next_pos_x = cur_pos.first + my_move[i][0];
            int next_pos_y = cur_pos.second + my_move[i][1];

            // cout << "cur pos : " <<  cur_pos.first << ", " << cur_pos.second << "\n";

            if(next_pos_x < 0 || next_pos_y < 0 || next_pos_x >= h || next_pos_y > w) continue;

            if(vis[next_pos_x][next_pos_y] != -1 || mat[next_pos_x][next_pos_y] == -1) continue;
            

            q.push(make_pair(next_pos_x, next_pos_y));
            vis[next_pos_x][next_pos_y] = vis[cur_pos.first][cur_pos.second] + 1;


            if (max_value < vis[next_pos_x][next_pos_y]) max_value = vis[next_pos_x][next_pos_y];
        }


    }



    return (max_value != -1) ? max_value : 0;


}


int main() {
    fastIO();
    
    int n, m;
    cin >> m >> n;

    vis.assign(n, vector<int> (m, -1));


    vector<vector<int>> mat(n, vector<int> (m));
    
    vector<pair<int, int>> start_pos;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            int val;
            cin >> val;

            if(val == 1) start_pos.push_back(make_pair(i, j));
            
            mat[i][j] = val;
        }
    }

    int max_value = bfs(start_pos, mat);

    // bool bt = false;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            if (vis[i][j] == -1 && mat[i][j] != -1){
            
                cout << -1 << "\n";
                return 0;
                
                
            }
        }
    }

    cout << max_value << "\n";

    return 0;
}