#include<bits/stdc++.h>

using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<int> vis;


string output = "";


void accece(vector<int>& his, int cur_val, int cur_depth, int limit_depth){

    if (cur_depth == limit_depth){

        for(auto& v : his){

            output += to_string(v) + " ";
        }

        output += to_string(cur_val) + "\n";

        // his.pop_back();

        return;
    }
    
    vis[cur_val] = 1;

    int n = vis.size() - 1;

    his.push_back(cur_val);

    for (int i=1; i<=n; i++){

        if(vis[i] == 1) continue;
        else{

            accece(his, i, cur_depth + 1, limit_depth);

        } 

    }

    his.pop_back();

    vis[cur_val] = 0;

    return;

}

int main(){

    fastIO();
    
    int n, m;
    cin >> n >> m;


    for(int i=1; i<=n; i++){

        vis.assign(n+1, 0);

        vector<int> his;

        accece(his, i, 1, m);

    }

    cout << output;


    return 0;
}