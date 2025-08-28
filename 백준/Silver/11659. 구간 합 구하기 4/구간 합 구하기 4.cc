#include<bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

string str = "";

int main() {
    fastIO();
    
    int n, m;
    cin >> n >> m;

    vector<int> arr(n+1);
    arr[0] = 0;
    for(int i=1; i<=n; i++){

        int value;
        cin >> value;

        arr[i] = arr[i-1] + value;
    }

    for(int i=0; i<m; i++){

        int start, end;
        cin >> start >> end;

        int sum = arr[end] - arr[start-1];
        
        str += to_string(sum) + "\n";

    }

    cout << str;

    return 0;
}