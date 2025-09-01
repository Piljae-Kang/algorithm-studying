#include<bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<int> dp, parent;
vector<int> operation;

int opt_function(int value, int opt_idx){
    int result;
    int n = value;

    if(opt_idx == 0){
        result = 2*n % 10000;
    }
    else if(opt_idx == 1){
        if(n == 0) result = 9999;
        else result = n-1;
    }
    else if(opt_idx == 2){
        int num = 0;
        for(int i=1000; i>=1; i=i/10){
            int digit = n/i;
            n -= digit * i;

            if (i == 1000){
                num += digit;
            }
            else{
                num += (digit*(i*10))%10000;
            }
        }
        result = num;
    }
    else if(opt_idx == 3){
        int num = 0;
        for(int i=1000; i>=1; i=i/10){
            int digit = n/i;
            n -= digit * i;

            if (i == 1){
                num += (digit*1000);
            }
            else{
                num += (digit*(i/10))%10000;
            }
        }
        result = num;
    }
    else{
        result = -1;
    }

    return result;
}

bool bfs(int start, int end){
    queue<int> q;
    q.push(start);
    dp[start] = 1;  // 방문 표시
    parent[start] = start;
    operation[start] = -1;

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        // if(cur == end) return true;

        for(int i=0; i<4; i++){
            int next = opt_function(cur, i);
        
            
            if(dp[next] == -1){  // 방문하지 않은 노드만
                dp[next] = 1;    // 방문 표시
                parent[next] = cur;
                operation[next] = i;
                q.push(next);

                if(next == end) return true;
            }
        }
    }

    return false;
}

void tracking(int start, int end){
    vector<string> path;
    int cur = end;
    
    while(cur != start){
        int opt = operation[cur];
        if(opt == 0) path.push_back("D");
        else if(opt == 1) path.push_back("S");
        else if(opt == 2) path.push_back("L");
        else if(opt == 3) path.push_back("R");
        cur = parent[cur];
    }
    
    for(auto it = path.rbegin(); it != path.rend(); it++) {
        cout << *it;
    }
    cout << "\n";
}

int main() {
    fastIO();

    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        dp.assign(10000, -1);
        parent.assign(10000, -1);
        operation.assign(10000, -1);

        int start, end;
        cin >> start >> end;

        bool success = bfs(start, end);

        if(success){
            tracking(start, end);
        }
        else{
            cout << "fail\n"; 
        }
    }

    return 0;
}