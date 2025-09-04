#include<bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<vector<int>> vis;

vector<vector<int>> move = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int cnt = 0;

bool off_flag = false;

pair<int, int> move_func(int i, int j, int dir, bool front){


    if (front == false) dir = (dir + 2)%4;


    if (dir == 0) return make_pair(i-1, j);
    else if (dir == 1) return make_pair(i, j+1);
    else if (dir == 2) return make_pair(i+1, j);
    else return make_pair(i, j-1);

}

bool isWall(vector<vector<int>>& mat, int s_i, int s_j){
    if(s_i < 0 || s_j < 0 || s_i >= mat.size() || s_j >= mat[0].size()) return true;

    if(mat[s_i][s_j] == 1) return true;

    return false;
}

void clean(vector<vector<int>>& mat, int s_i, int s_j, int dir){

    int c_i = s_i;
    int c_j = s_j;
    int c_dir = dir;
    int count = 0;

    bool has_empty = false;

    while(true){

        if(isWall(mat, c_i, c_j)) break;

        if (vis[c_i][c_j]==0){
            vis[c_i][c_j] = 1;
            cnt++;
        }

        // if(count == 10) break;

        // cout << count << " : " <<  c_i << ", " << c_j << "\n";
        // cout << "cnt" << " : " <<  cnt << "\n";

        count++;


        // cout << c_i << ", " << c_j << "\n";

        has_empty = false;

        for(int i=1; i<=4; i++){

            int next_dir = (c_dir - i + 4) % 4;
            pair<int, int> next_ij = move_func(c_i, c_j, next_dir, true);

            // cout << "next : " << next_ij.first << ", " << next_ij.second << "\n";
    
            int next_i = next_ij.first;
            int next_j = next_ij.second;
    
            if(vis[next_i][next_j] == 0 && !isWall(mat, next_i, next_j)){

                c_i = next_i; c_j = next_j; c_dir = next_dir;
                has_empty = true;

                break;
            }

        }

        if(has_empty == false){

            pair<int, int> back_ij = move_func(c_i, c_j, c_dir, false);

            if(isWall(mat, back_ij.first, back_ij.second)){

                return;
            }
            else{
                c_i = back_ij.first; c_j = back_ij.second;
            }

        }



    }

}



int main() {
    fastIO();


    int n, m;
    cin >> n >> m;

    int s_i, s_j, dir;

    cin >> s_i >> s_j >> dir;

    vector<vector<int>> mat(n, vector<int> (m));

    vis.assign(n, vector<int> (m, 0));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){

            cin >> mat[i][j];

        }
    }


    // dfs(mat, s_i, s_j, dir);
    clean(mat, s_i, s_j, dir);

    cout << cnt << "\n";


    return 0;
}