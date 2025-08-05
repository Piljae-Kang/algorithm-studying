#include <bits/stdc++.h>

void fast_io() {
    std::ios::sync_with_stdio(false);
    
    std::cin.tie(NULL); 
    std::cout.tie(NULL);
}

int main(){

    fast_io();

    std::set<int> s;
    int cnt = 0;
    
    for (int i=1; i<=10; i++){

        int n;

        std::cin >> n;

        int m = n % 42;

        if (s.find(m) == s.end()){
            
            s.insert(m);
            cnt++;
        }

    }

    std::cout << cnt << std::endl;

    return 0;

}