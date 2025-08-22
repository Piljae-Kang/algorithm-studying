#include<bits/stdc++.h>


using namespace std;

vector<vector<int>> visited;


int room_find(int x, int y, vector<vector<int>>& mat, int cnt){

    if(x < 0 || x >= mat.size() || y < 0 || y >= mat[0].size()) return 0;
    if(mat[x][y] == 0 || visited[x][y] == 1) return 0;


    visited[x][y] = 1;
    
    int size = 1;

    size += room_find(x+1, y, mat, cnt);
    size += room_find(x-1, y, mat, cnt);
    size += room_find(x, y+1, mat, cnt);
    size += room_find(x, y-1, mat, cnt);


    return size;

}


int main(){

    
    int num;
    cin >> num;


    vector<vector<int>> mat(num, vector<int>(num));

    visited.assign(num, vector<int>(num, 0));


    for(int i=0; i<num; i++){

        string line;
        cin >> line;


        int cnt=0;
        for(char ch : line){

            int num = ch - '0';

            mat[i][cnt] = num;
            cnt++;
        }

    }

    int room_cnt = 0;

    vector<int> room_size_arr;

    for(int i=0; i<num; i++){

        for(int j=0; j<num; j++){

            if(visited[i][j] == 0 && mat[i][j] == 1){

                int room_size = room_find(i, j, mat, 0);
                room_size_arr.push_back(room_size);
            }


        }
    }

    sort(room_size_arr.begin(), room_size_arr.end());


    cout << room_size_arr.size() << "\n";

    for(int value : room_size_arr){

        cout << value << "\n";
    }



    return 0;
}