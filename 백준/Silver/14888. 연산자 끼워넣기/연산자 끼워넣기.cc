#include<bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

string str = "";


vector<int> vis;


int min_value = INT_MAX;
int max_value = INT_MIN;

int opt_function(int a, int b, int opt_idx){

    if (opt_idx == 0){

        return a + b;

    }
    else if (opt_idx == 1){
        
        return a - b;
    }
    else if (opt_idx == 2){
        
        return a * b;
    }
    else{

        if(a<0 && b >0){

            a *= -1;

            return -(a / b);
        }
        else{
            return a / b;
        }
        
    }

}

void dfs(vector<int>& arr, int n, int opt_idx, int result){

    if(n == arr.size() - 1){

        int total = opt_function(result, arr[n], opt_idx);

        // cout << result << "\n";
        // cout << arr[n] << "\n";
        // cout << total << "\n";

        max_value = max(total, max_value);
        min_value = min(total, min_value);

        return;
    }

    vis[opt_idx]--;

    int value = opt_function(result, arr[n], opt_idx);

    for(int i=0; i<4; i++){

        int v;

        if(vis[i] == 0) continue;

        else{

            dfs(arr, n + 1, i, value);

        }

    }

    vis[opt_idx]++;

    return;
}

int main() {
    fastIO();
    
    int n;
    cin >> n;

    vector<int> arr(n);

    vis.assign(n, 0);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    for(int i=0; i<4; i++){

        cin >> vis[i];
    }


    for(int i=0; i<4; i++){

        if(vis[i] != 0){

            dfs(arr, 1, i, arr[0]);
        }


    }


    cout << max_value << "\n";
    cout << min_value << "\n";

    return 0;
}