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


    std::vector<std::string> v_erase;

    v_erase.push_back(v[0]);
    std::string last_v = v[0];

    for(auto it = v.begin()+1; it < v.end(); it++){

        if (last_v != *it){

            v_erase.push_back(*it);
            last_v = *it;
        }
        else{
            continue;
        }


    }


    for(int i=0; i<v_erase.size(); i++){

        std::cout << v_erase[i] << std::endl;

    }

    return 0;

}