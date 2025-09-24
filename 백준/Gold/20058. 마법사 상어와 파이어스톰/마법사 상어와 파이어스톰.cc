#include<bits/stdc++.h>
using namespace std;


long long max_ice_size = 0;
long long max_ice_cnt = 0;



void fire_strom(vector<vector<int>>& mat, int Q){



    vector<vector<int>> new_mat(mat.size(), vector<int>(mat[0].size(), 0));


    int level_size = pow(2, Q);

    for(int i=0; i<mat.size(); i+= level_size){
        for(int j=0; j<mat.size(); j+= level_size){


            for(int a=0; a<level_size; a++){
                for(int b=0; b<level_size; b++){
                    
                    int u = i + b;
                    int v = j + level_size - 1 - a;

                    new_mat[u][v] = mat[i + a][j + b];

                }
            }
        
        }
    
    }


    mat = move(new_mat);

}


void melting_ice(vector<vector<int>>& mat){



    vector<vector<int>> new_mat(mat.size(), vector<int>(mat[0].size(), 0));

    vector<vector<int>> move_f = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};


    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat.size(); j++){


        int ice_cnt = 0;
        for(int m=0; m<4; m++){
            
            int u = i + move_f[m][0];
            int v = j + move_f[m][1];

            
            if (u <0 || v<0 || u >= mat.size() || v >= mat[0].size()) continue;

            if(mat[u][v] == 0) continue;

            ice_cnt++;
        }

            if(ice_cnt < 3 && mat[i][j] > 0) {

                new_mat[i][j] = mat[i][j] - 1;
            }
            else{

                new_mat[i][j] = mat[i][j];
            } 
        }
    
    }

    mat = move(new_mat);
}


void print_mat(vector<vector<int>>& mat){


    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[0].size(); j++){


            cout << mat[i][j] << " ";

        }

        cout << "\n";
    }
}


void find_ice(vector<vector<int>>& mat){


    vector<vector<int>> visited(mat.size(), vector<int> (mat[0].size(), 0));

    vector<vector<int>> move = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, -1}, {1, -1}, {1, 1}, {-1, 1}};


    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[0].size(); j++){

            if(visited[i][j] == 1) continue; // 이미 ice로 판정

            if(mat[i][j] == 0) continue; // 이미 녹음

            int ice_size = 0;
            int ice_cnt = 0;


            queue<pair<int, int>> q;

            q.push(make_pair(i, j));
            visited[i][j] = 1;

            ice_cnt++;
            ice_size += mat[i][j];

            while(!q.empty()){

                int curr_u = q.front().first;
                int curr_v = q.front().second;

                q.pop();

                for(int i=0; i<4; i++){

                    int next_u = curr_u + move[i][0];
                    int next_v = curr_v + move[i][1];

                    if (next_u <0 || next_v<0 || next_u >= mat.size() || next_v >= mat[0].size()) continue;

                    if(visited[next_u][next_v] != 0 || mat[next_u][next_v] == 0) continue;

                    q.push(make_pair(next_u, next_v));

                    visited[next_u][next_v] = 1;

                    ice_cnt++;
                    ice_size += mat[next_u][next_v];
                }

            }



            if(max_ice_cnt < ice_cnt) max_ice_cnt = ice_cnt;

            max_ice_size += ice_size;


        }

    }





}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;

    cin >> N >> Q;

    int width = pow(2, N);

    int height = width;

    vector<vector<int>> mat(height, vector<int> (width));

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){

            cin >> mat[i][j];

        }
    }

    vector<int> Q_arr(Q); 

    for(int i=0; i<Q; i++){

        cin >> Q_arr[i];
    }

    int q_cnt = 0;

    for(int q : Q_arr){


        fire_strom(mat, q);
        melting_ice(mat);

        // cout << "-----------------------------\n";
        // cout << q_cnt  <<"\n";
        // cout << "-----------------------------\n";

        // print_mat(mat);


        // cout << "-----------------------------\n";

        q_cnt++;
    }

    find_ice(mat);

    cout << max_ice_size << "\n" << max_ice_cnt << "\n";

    return 0;
}