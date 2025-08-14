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

    int sum = 0;

    for(int i=0; i<n; i++){

        std::cin >> v[i];

        sum += v[i];
    }

    std::sort(v.begin(), v.end());

    std::vector<std::pair<int, int>> count_v;
    std::set<int> key_set;

    for (int p : v){
        
        auto it = std::find_if(count_v.begin(), count_v.end(), [p](const std::pair<int, int>& pair) {
            return pair.first == p;
        });
    
        if (it == count_v.end()) {
            count_v.push_back({p, 1});
        } else {
            it->second++;
        }
    }

    std::sort(count_v.begin(), count_v.end(), [](const std::pair<int, int> a, const std::pair<int, int> b){

        if (a.second != b.second) return a.second > b.second;
        else return a.first < b.first;


    });

    int dup_value = 0;
    
    if (count_v.size() > 1){

        if (count_v[0].second == count_v[1].second){

            dup_value = count_v[1].first;
        }
        else dup_value = count_v[0].first;

    }
    else dup_value = count_v[0].first;


    std::cout << int(round(double(sum) / n)) << "\n";
    std::cout << v[(n/2)] << "\n";
    std::cout << dup_value << "\n";
    std::cout << v[v.size() - 1] - v[0] << "\n";


    return 0;
}