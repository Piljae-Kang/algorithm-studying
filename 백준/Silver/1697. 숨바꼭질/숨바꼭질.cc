#include<bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<int> my_move = {-1, 1, 2};
vector<int> vis;


void bfs(int start, int dest_pos){

    queue<int> q;
    q.push(start);
    vis[start] = 0;

    while(!q.empty()){

        int cur_pos = q.front();
        q.pop();

        for(int i=0; i<3;i++){

            int next_pos;
            if(i < 2){

                next_pos = cur_pos + my_move[i];

            }
            else{
                next_pos = cur_pos * my_move[i];

            }

            // cout << "next : " << next_pos << "\n";

            if(next_pos < 0 || next_pos >= vis.size()) continue;
            if(vis[next_pos] != -1) continue;

            q.push(next_pos);
            vis[next_pos] = vis[cur_pos] + 1;

            if(next_pos == dest_pos){
            // cout << "vis[k] : " << vis[next_pos] << "\n";
            return;

            }

        }

    }

    return;

}

int main() {
    fastIO();
    
    int n, k;
    cin >> n >> k;

    vis.assign(200000, -1);

    bfs(n, k);
    int cnt = vis[k];

    cout << cnt << "\n";

    return 0;
}