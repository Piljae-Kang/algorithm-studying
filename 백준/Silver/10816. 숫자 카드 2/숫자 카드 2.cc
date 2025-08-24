#include<bits/stdc++.h>

using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){

    fastIO();
    
    int N;
    cin >> N;
    
    vector<int> arr(N);

    for(int i=0; i<N; i++){

        cin >> arr[i];

    }

    sort(arr.begin(), arr.end());

    int M;

    cin >> M;

    string output = "";

    for(int i=0; i<M; i++){

        int num;

        cin >> num;

        auto range = equal_range(arr.begin(), arr.end(), num);

        int dis = distance(range.first, range.second);

        output += to_string(dis) + " ";

    }

    cout << output;


    return 0;
}