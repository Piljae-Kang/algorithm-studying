#include<bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

string output = "";

vector<int> vis, dp;



int w(int a, int b, int c){

    if (a <= 0 | b <= 0 | c <= 0){

        return 1;
    }

    if (a > 20 | b > 20 | c > 20){
        
        return w(20, 20, 20);
    }

    int idx = a * 21 * 21 + b * 21 + c;

    if(vis[idx] == 1) return dp[idx];

    vis[idx] = 1;

    int result;

    if(a < b && b < c){

        result = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
        dp[idx] = result;
        return  result;
    }
    
    else{

        result =   w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
        dp[idx] = result;

        return result;
    }

}

int main() {
    fastIO();

    vis.assign(21*21*21, 0);
    dp.assign(21*21*21, 0);

    
    while(true){

        int a,b,c;

        cin >> a >> b >> c;

        if(a==-1 && b==-1 && c==-1){

            break;

        }


        int result = w(a, b, c);

        string str = "w(" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + ") = " + to_string(result) + "\n";

        output += str;
    }

    cout << output;

    return 0;
}