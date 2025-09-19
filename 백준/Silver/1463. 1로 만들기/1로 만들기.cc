#include<bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


vector<int> dp;


int my_func(int num){


    if(num == 1) return 0;

    if (dp[num] != -1){

        // cout << "0" << "\n";


        return dp[num];

    } 

    // 여기서 부터 내려감.
    int min_value = INT_MAX;
    int value;

    // cout << "num : " << num << "\n";

    if(num % 3 == 0){
        
        // cout << "1" << "\n";

        value = my_func(num/3); 

        if (value < min_value) min_value = value;
    }
    if (num % 2 == 0){

        // cout << "2" << "\n";
        value = my_func(num/2); 
        if (value < min_value) min_value = value;
    }
        // cout << "3" << "\n";

    value = my_func(num - 1);
    if (value < min_value) min_value = value;
    

    dp[num] = min_value + 1;

    // printf("dp[%d] : %d\n", num, dp[num]); 

    return dp[num];
}


int main() {
    fastIO();

    int num;

    cin >> num;

    dp.assign(num + 1, -1);

    dp[1] = 0;

   int output = my_func(num);

    cout << output << "\n";
    
    return 0;
}