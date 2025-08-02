#include <bits/stdc++.h>

void fast_io() {
    std::ios::sync_with_stdio(false);
    
    std::cin.tie(NULL); 
    std::cout.tie(NULL);
}


int main(){

    fast_io();
    
    int n = 9;


    std::vector<int> v(n);

    int max_index = -1;
    int max_value = INT_MIN;

    for(int i=0; i<n; i++){

        std::cin >> v[i];

        if (v[i] > max_value){

            max_index = i;
            max_value = v[i];


        }

    }

    std::cout << max_value << std::endl;
    std::cout << max_index + 1 << std::endl;

    return 0;

}