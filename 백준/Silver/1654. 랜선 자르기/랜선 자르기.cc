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


    vector<unsigned int> arr(n);

    unsigned int max_value = 0;

    for(int i=0; i<n; i++){

        cin >> arr[i];

        if(arr[i] > max_value) max_value = arr[i];
    }


    unsigned int left = 1;
    unsigned int right = max_value;
    unsigned int mid;

    unsigned int max_idx = 1;


    while(left <= right){

        mid = (left + right) / 2;


        unsigned int sum = 0;

        for(int j=0; j<n; j++){

            sum += arr[j] / mid;

        }

        if (sum >= m){

            left = mid + 1;

            max_idx = max(max_idx, mid);

        }
        else{

            right = mid - 1;

        }

    }


    cout << max_idx << "\n";

    return 0;
}