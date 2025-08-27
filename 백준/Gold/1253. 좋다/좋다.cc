#include<bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

bool find_good_idx(vector<int>& arr, int idx){
    
    int p1 = 0;
    int p2 = arr.size() - 1;

    bool result = false;

    int num = arr[idx];

    while(true){

        if(p1 >= p2) break;

        int sum = arr[p1] + arr[p2];

        if(sum == arr[idx]){

            if(idx == p1){

                p1 += 1;
            }
            else if(idx == p2){
                p2 -= 1;
            }
            else{

                result = true;
                break;

            }

        }
        
        if(sum < num){

            p1 += 1;
        }

        if(sum > num){
            
            p2 -= 1;
        }

        // cout << arr[p1] << ", " << arr[p2] << ", " << sum << "\n";

        // cout << p1 << ", " << p2 << "\n";

    }

    return result;
}

int main() {
    fastIO();
    
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0; i<n; i++){

        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int good_cnt = 0;
    for(int i=0; i<n; i++){

        if(find_good_idx(arr, i)) good_cnt++;
    }

    cout << good_cnt << "\n";

    return 0;
}