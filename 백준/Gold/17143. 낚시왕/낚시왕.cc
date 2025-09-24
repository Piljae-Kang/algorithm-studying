#include<bits/stdc++.h>
using namespace std;


struct shark{

    pair<int, int> pos;
    int speed;
    int direction;
    int size;

    bool catch_flag;

};


vector<vector<int>> shark_map;



shark move_func(int u, int v, int dir, int speed, int R, int C){

    int pos_u = u;
    int pos_v = v;

    if(dir == 1 || dir == 2){ // 상하

        for(int i=0; i<speed; i++){

            if(dir == 1){

                if(pos_u == 0){

                    dir = 2;
                    pos_u++;
                    continue;

                }
                
                else{

                    pos_u--;
                }
            }

            if(dir == 2){

                if(pos_u == R -1){

                    dir = 1;
                    pos_u--;
                    continue;
                }
                else{

                    pos_u++;
                }

            }

        }


    }
    else{

        for(int i=0; i<speed; i++){

            if(dir == 4){

                if(pos_v == 0){

                    dir = 3;
                    pos_v++;
                    continue;

                }
                
                else{

                    pos_v--;
                }
            }

            if(dir == 3){

                if(pos_v == C -1){

                    dir = 4;
                    pos_v--;
                    continue;
                }
                else{

                    pos_v++;
                }

            }

        }

    }


    shark new_shark;

    new_shark.pos = make_pair(pos_u, pos_v);
    new_shark.direction = dir;
    new_shark.speed = speed;

    return new_shark;

}

void shark_move(vector<shark>& shark_arr, int R, int C){

    shark_map.assign(R, vector<int> (C, -1));

    // cout << "shar arr size : " << shark_arr.size() << "\n";

    for(int i=0; i<shark_arr.size(); i++){

        if(shark_arr[i].catch_flag) continue;


        int u = shark_arr[i].pos.first;
        int v = shark_arr[i].pos.second;
        int dir = shark_arr[i].direction;
        int speed = shark_arr[i].speed;

        // shark_map[u][v] = -1;

        // printf("%d : u, v, dir, speed : %d, %d, %d, %d\n", i, u, v, dir, speed);


        shark new_shark = move_func(u, v, dir, speed, R, C);

        shark_arr[i].pos = new_shark.pos;
        shark_arr[i].direction = new_shark.direction;

        // printf("%d : New u, v, dir, speed : %d, %d, %d, %d\n", i, new_shark.pos.first, new_shark.pos.second, new_shark.direction, speed);

        // cout << "\n";

        int new_u = new_shark.pos.first; int new_v = new_shark.pos.second;

        if(shark_map[new_u][new_v] != -1){ // 이미 존재재

            int prev_idx = shark_map[new_u][new_v]; // 전의 idx

            if(shark_arr[prev_idx].size <= shark_arr[i].size){ // 큰걸로

                shark_map[new_u][new_v] = i;
                shark_arr[prev_idx].catch_flag = true;

            }
            else{

                shark_arr[i].catch_flag = true;
            }



        }
        else{
            shark_map[new_u][new_v] = i;
    
        }

    }


}

void print_mat(){

    for(int i=0; i<shark_map.size(); i++){
        
        for(int j=0; j<shark_map[0].size(); j++){


            cout << shark_map[i][j] << " ";

        
        }

        cout << "\n";
    

    }


}


int remove_shark(vector<shark>& shark_arr, int person_col_idx){


    int shark_row_idx = -1;

    int shark_idx = -1;

    for(int i=0; i<shark_map.size(); i++){

        if(shark_map[i][person_col_idx] != -1){


            shark_idx = shark_map[i][person_col_idx];
            break;
        }
    }

    if(shark_idx != -1){ // shark 발견

        shark_arr[shark_idx].catch_flag = true;

        int u = shark_arr[shark_idx].pos.first;
        int v = shark_arr[shark_idx].pos.second;


        shark_map[u][v] = -1;


        return shark_arr[shark_idx].size;

    }
    else{

        return 0;
    }

    
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C, M;

    cin >> R >> C >> M;

    shark_map.assign(R, vector<int> (C, -1));


    vector<shark> shark_arr;

    for(int i=0; i<M; i++){

        int pos_r, pos_c, s, d, z;
        cin >> pos_r >> pos_c >> s >> d >> z;

        shark sk;

        sk.pos = make_pair(pos_r - 1, pos_c - 1);
        sk.direction = d;
        sk.speed = s;
        sk.size = z;
        sk.catch_flag = false;
        
        shark_arr.push_back(sk);

        shark_map[pos_r - 1][pos_c - 1] = i;

    }


    int total_size = 0;


    for(int i=0; i<C; i++){

        // cout << "------------------------\n";

    
        // print_mat();
    
        int size = remove_shark(shark_arr, i);
    
    
        // cout << "size : " << size << "\n";
    
        // cout << "------------------------\n";
    
        total_size += size;
    
        shark_move(shark_arr, R, C);
    
        // print_mat();
    
        // cout << "------------------------\n";


    }

    // cout << "total : " << total_size << "\n";
    cout << total_size << "\n";
    
    return 0;
}