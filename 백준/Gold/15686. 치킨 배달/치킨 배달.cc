#include<bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

vector<int> visited;
vector<int> result;

int min_result = INT_MAX;

int chicken_distance(pair<int, int> a, pair<int, int> b){

    return abs(a.first - b.first) + abs(a.second - b.second);
}


void cal_city_chicken(vector<pair<int, int>>& house_list, vector<pair<int, int>>& chicken_list){

    int city_chicken_dis = 0;

    for(int i=0; i<house_list.size(); i++){

        int min_dis = INT_MAX;

        for(int index : result){

            int dis = chicken_distance(chicken_list[index], house_list[i]);

            if (dis < min_dis) min_dis = dis;

        }

        // cout << "min_dis : " << min_dis << "\n";

        city_chicken_dis += min_dis;
    }

    // cout << "city chicken dis : " << city_chicken_dis << "\n";

    if(min_result > city_chicken_dis) min_result = city_chicken_dis;
}

void combination(vector<pair<int, int>>& house_list, vector<pair<int, int>>& chicken_list, int depth_limit, int depth, int start){

    if(depth == depth_limit){

        // for(int i=0; i<result.size(); i++){

        //     cout << result[i] << " ";
        // }
        // cout << "\n";

        cal_city_chicken(house_list, chicken_list);

        return;
    }


    for(int i=start; i<chicken_list.size(); i++){
        
        result.push_back(i);
        combination(house_list, chicken_list, depth_limit, depth + 1, i + 1);
        result.pop_back();

    }

}


int main() {
    fastIO();

    int n, m;

    cin >> n >> m;

    vector<pair<int, int>> chicken_list;
    
    vector<pair<int, int>> house_list;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            int value;

            cin >> value;

            if(value == 1){
                house_list.push_back(make_pair(i, j));
            }
            else if (value == 2){
                chicken_list.push_back(make_pair(i, j));
            }

        }
    }

    visited.assign(chicken_list.size(), 0);

    int max_value = INT_MIN;

    for(int i=1; i<=m; i++){
    
        // int value = combination(house_list, chicken_list, i, 0, 0);
        // if(max_value < value) max_value = value;

        combination(house_list, chicken_list, i, 0, 0);

    }

    cout << min_result << "\n";
    
    return 0;
}