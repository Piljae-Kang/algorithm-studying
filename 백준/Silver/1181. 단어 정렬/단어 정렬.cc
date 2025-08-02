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

    std::vector<std::string> v(n);

    for(int i=0; i<n; i++){

        std::cin >> v[i];

    }


    std::sort(v.begin(), v.end(), [](std::string a, std::string b) {

        if (a.length() == b.length()){

            return a < b;
        }
        else {

            return a.length() < b.length();
        }

    });


    v.erase(std::unique(v.begin(), v.end()), v.end());


    for(int i=0; i<v.size(); i++){

        std::cout << v[i] << std::endl;

    }

    return 0;

}