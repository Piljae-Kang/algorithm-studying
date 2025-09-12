#include<bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


vector<vector<int>> move_func = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void diffusion(vector<vector<int>>& mat, int R, int C){

    vector<vector<int>> next_mat(R, vector<int> (C, 0));

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){

            if(mat[i][j] == -1){

                next_mat[i][j] = -1;

            }
            else if(mat[i][j] == 0) continue;
            else{

                int neighbor_cnt = 0;

                int neighbor_value = mat[i][j] / 5;

                for(int k=0; k<4; k++){
                    

                    int i_n = i + move_func[k][0];
                    int j_n = j + move_func[k][1];

                    if(i_n < 0 || j_n < 0 || i_n >= R || j_n >= C) continue;
                    else if(mat[i_n][j_n] == -1) continue;
                    else neighbor_cnt++;

                    next_mat[i_n][j_n] += neighbor_value;
                }

                next_mat[i][j] += (mat[i][j] - (neighbor_cnt * neighbor_value));

            }

        }
    }

    // mat = next_mat;
    mat = move(next_mat);
}


void clean(vector<vector<int>>& mat, const vector<pair<int, int>>&  air_cleaner_poses){


    vector<vector<int>> new_mat = mat;

    int height = mat.size(); int width = mat[0].size();


    /// top clean start

    pair<int, int> air_top = air_cleaner_poses[0];

    for(int i=2; i<width; i++){

        new_mat[air_top.first][i] = mat[air_top.first][i - 1];
    }
    new_mat[air_top.first][1] = 0;

    for(int i=air_top.first -1; i >=0; i--){
        new_mat[i][width - 1] = mat[i + 1][width - 1];
    }

    for(int i=width - 2; i>=0; i--){

        new_mat[0][i] = mat[0][i + 1];
    }

    for(int i=1; i<air_top.first; i++){

        new_mat[i][0] = mat[i-1][0];
    }


    /// bottom clean start


    pair<int, int> air_bottom = air_cleaner_poses[1];

    for(int i=2; i<width; i++){

        new_mat[air_bottom.first][i] = mat[air_bottom.first][i - 1];
    }
    new_mat[air_bottom.first][1] = 0;

    for(int i=air_bottom.first + 1; i < height; i++){
        new_mat[i][width - 1] = mat[i - 1][width - 1];
    }

    for(int i=width - 2; i>=0; i--){

        new_mat[height - 1][i] = mat[height - 1][i + 1];
    }

    for(int i= height - 2; i>air_bottom.first; i--){

        new_mat[i][0] = mat[i+1][0];
    }

    mat = move(new_mat);

}

void print_matrix(const vector<vector<int>>& mat){

    cout <<"----------------\n";
    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[0].size(); j++){

            cout << mat[i][j] << " ";

        }

        cout <<"\n";
    }

    cout <<"----------------\n";
}


int main() {
    fastIO();

    int R, C, T;
    cin >> R >> C >> T;

    vector<vector<int>> mat(R, vector<int> (C));

    vector<pair<int, int>>  air_cleaner_poses;    

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){

            cin >> mat[i][j];

            if(mat[i][j] == -1){

                air_cleaner_poses.push_back(make_pair(i, j));
            }

        }
    }


    for(int i=0; i<T; i++){

        // cout << " i : " << i << "\n";

        diffusion(mat, R, C);
        // print_matrix(mat);
        clean(mat, air_cleaner_poses);
        // print_matrix(mat);

    }

    int total_dust = 0;

    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
     
            if(mat[i][j] != -1){

                total_dust += mat[i][j];
            }
        }
    }


    cout << total_dust << "\n";
    
    return 0;
}