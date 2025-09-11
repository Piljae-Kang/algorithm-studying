#include<bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int max_value = INT_MIN;

// int jg_cnt = 0;

void print_matrix(const vector<vector<int>>& mat){

    for(int i=0; i<mat.size(); i++){
        for(int j=0; j<mat[0].size(); j++){

            cout << mat[i][j] << " ";
        
        }

        cout << "\n";

    }

}


void print_vector(const vector<int>& v){

    for(int i : v){

        cout << i << " "; 
    }
    cout << "\n";
}

void check_max(int a){

    if (a > max_value) max_value = a;
}

vector<int> move_list(deque<int> dq, bool move_right){

    deque<int> v;

    int zero_cnt = 0;
    int prev_v = -1;
    while(true){

        if(dq.empty()){

            if(prev_v != -1){
                check_max(prev_v);
                v.push_front(prev_v);
            }

            break;
        }

        int value = dq.back();
        dq.pop_back();

        if(value == 0) zero_cnt++; 

        else{

            if(prev_v == -1){
                prev_v = value;
            }

            else if(prev_v != value){

                check_max(prev_v);
                v.push_front(prev_v);
                prev_v = value;
            }
            else{
                check_max(prev_v * 2);
                v.push_front(prev_v * 2);
                zero_cnt++;

                prev_v = -1;
            }

        }

    }

    for(int i=0; i<zero_cnt; i++){
        v.push_front(0);
    }
    
    vector<int> new_v(v.begin(), v.end());

    return new_v;
}

vector<vector<int>> move_mat(vector<vector<int>> mat, int direction){

    // jg_cnt++;

    if(direction == 0){ // move up

        for(int i=0; i<mat.size(); i++){

            deque<int> dq;

            for(int j=0; j<mat.size(); j++){

                dq.push_front(mat[j][i]);
            }

            vector<int> v = move_list(dq, true);
            // cout << i << " : ";
            // print_vector(v);

            int len = mat.size() - 1;

            for(int j=0; j<mat.size(); j++){
                mat[j][i] = v[len - j];
            }

        }

        return mat;
    }
    else if (direction == 1){ // move right

        for(int i=0; i<mat.size(); i++){

            deque<int> dq(mat[i].begin(), mat[i].end());

            vector<int> v = move_list(dq, true);
            // cout << i << " : ";
            // print_vector(v);
            mat[i] = v;
        }

        return mat;
    }
    else if (direction == 2){ // move down

        for(int i=0; i<mat.size(); i++){

            deque<int> dq;

            for(int j=0; j<mat.size(); j++){

                dq.push_back(mat[j][i]);
            }

            vector<int> v = move_list(dq, true);
            // cout << i << " : ";
            // print_vector(v);

            for(int j=0; j<mat.size(); j++){
                mat[j][i] = v[j];
            }

        }
        
        return mat;
    }
    else { // move left


        for(int i=0; i<mat.size(); i++){

            deque<int> dq;

            for(int j=0; j<mat.size(); j++){
                dq.push_front(mat[i][j]);
            }

            vector<int> v = move_list(dq, true);
            // cout << i << " : ";
            // print_vector(v);

            int len = mat.size() - 1;

            for(int j=0; j<mat.size(); j++){
                mat[i][j] = v[len - j];
            }

        }
        
        return mat;
    }

}

void simulation(vector<vector<int>> mat, int depth){

    if(depth == 5) return;

    for(int dir = 0; dir<4; dir++){

        vector<vector<int>> new_mat = move_mat(mat, dir);
        // cout << " depth = " << depth << ", dir = " << dir << "\n";
        // print_matrix(mat);

        simulation(new_mat, depth + 1);
        
    }

}




int main() {
    fastIO();

    int n;
    cin >> n;

    vector<vector<int>> mat(n, vector<int> (n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            int value;
            cin >> value;

            if(value > max_value) max_value = value;

            mat[i][j] = value;
        }
    }


    // move_mat(mat, 3);

    // print_matrix(mat);

    // move_mat(mat, 3);
    // print_matrix(mat);

    // move_mat(mat, 0);
    // print_matrix(mat);

    simulation(mat, 0);

    cout << max_value << "\n";
    // cout << jg_cnt << "\n";

    
    return 0;
}