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

    std::set<std::string> workers;

    for(int i=0; i<n; i++){

        std::string name;
        std::string state;

        std::cin >> name >> state;

        if(state == "enter"){

            workers.insert(name);
        }
        else{
            workers.erase(name);
        }
    }

    // set을 vector로 복사
    std::vector<std::string> workers_vec(workers.begin(), workers.end());   

    std::sort(workers_vec.begin(), workers_vec.end(), [](const std::string a, const std::string b){

        return a > b;
    });

    for (std::string worker : workers_vec){

        std::cout << worker << "\n";
    }

    return 0;
}