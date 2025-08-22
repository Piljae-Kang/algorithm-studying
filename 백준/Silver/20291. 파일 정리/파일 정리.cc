#include<bits/stdc++.h>

using namespace std;

int main(){

    
    int N;
    cin >> N;

    unordered_map<string, int> map;

    for(int i=0; i<N; i++){

        string str;

        cin >> str;

        size_t pos = str.find('.');

        string extension = str.substr(pos+1);

        if(map.find(extension) != map.end()){

            map[extension]++;
        }

        else{
            map[extension] = 1;

        }
    }

    vector<pair<string, int>> map_v(map.begin(), map.end());

    sort(map_v.begin(), map_v.end(), [](pair<string, int> a, pair<string, int> b){

        return a.first < b.first;
    });

    
    for (pair<string, int> item : map_v){

        cout << item.first << " " << item.second << "\n";
    }


    return 0;
}