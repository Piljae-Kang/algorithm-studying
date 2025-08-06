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
    std::vector<std::pair<int, int>> index_map;
    std::unordered_map<int, std::string> members_map;

    for (int i=0; i<n; i++){

        int age;
        std::string name;

        std::cin >> age >> name;

        index_map.push_back({i, age});
        members_map[i] = name;

    }

    std::sort(index_map.begin(), index_map.end(), [](std::pair<int, int>& a, std::pair<int, int>& b){

        if (a.second == b.second){

            return a.first < b.first;
        }
        else{

            return a.second < b.second;
        }


    });

    for (const auto &item : index_map){

        std::cout << item.second << " " << members_map[item.first] << "\n";

    }

    return 0;

}