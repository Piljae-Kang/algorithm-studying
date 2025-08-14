#include <bits/stdc++.h>

void fast_io() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); 
    std::cout.tie(NULL);
}

int main(){
    fast_io();

    int n;

    std::cin >> n;

    std::vector<int> v(n);

    for(int i=0; i<n; i++){

        std::cin >> v[i];
    }

    std::sort(v.begin(), v.end());

    int total = 0;
    int sum = 0;

    for (int p : v){

        sum += p;
        total += sum;

    }


    std::cout << total << "\n";


    return 0;
}