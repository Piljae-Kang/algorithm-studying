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

    std::vector<int> v;


    for (int i=0; i<n; i++){
        int num;
        std::cin >> num;
        v.push_back(num);
    }

    std::sort(v.begin(), v.end());

    // std::set<int> s(v.begin(), v.end());
    

    int m;
    std::cin >> m;

    for(int i=0; i<m; i++){

        int num;

        std::cin >> num;

        if(std::binary_search(v.begin(), v.end(), num)){
            std::cout << 1 << "\n";
        } else {
            std::cout << 0 << "\n";
        }

    }


    return 0;

}