// #include<bits/stdc++.h>

#include<iostream>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>
#include<climits>


using namespace std;

// vector<int> shortest_dis;

// vector<vector<vector<int>>> shortest_dis;


struct user_info{

    pair<int, int> start_pos;
    pair<int, int> destination_pos;

};



void update_st_dis(vector<vector<int>>& dist, pair<int, int> des_pos, int idx, int N, int M){

}

int find_shorest_path(vector<vector<int>>& mat, pair<int, int> start_pos, pair<int,int> dest_pos){

    queue<pair<int, int>> q;

    q.push(start_pos);


    vector<vector<int>> move_func = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    vector<vector<int>> dist(mat.size(), vector<int> (mat[0].size(), 0));

    while(!q.empty()){


        pair<int, int> curr_pos = q.front();
        q.pop();
        if (curr_pos.first == dest_pos.first && curr_pos.second == dest_pos.second){

            return dist[curr_pos.first][curr_pos.second];

        }




        for(int i=0; i<4; i++){


            int next_u = curr_pos.first + move_func[i][0];
            int next_v = curr_pos.second + move_func[i][1];


            if(next_u <0 || next_v < 0 || next_u >= mat.size() || next_v >= mat[0].size()) continue;

            if(dist[next_u][next_v] != 0) continue;

            if(mat[next_u][next_v] == 1) continue;

            q.push(make_pair(next_u, next_v));

            dist[next_u][next_v] = dist[curr_pos.first][curr_pos.second] + 1;

            if (next_u == dest_pos.first && next_v == dest_pos.second){

                 return dist[next_u][next_v];
            }

        }

    }

    return -1;

}


int driving(vector<vector<int>>& mat, vector<user_info>& user_infos, pair<int, int> start_pos, int F){


    int fuel = F;

    int M = user_infos.size();


    vector<bool> check(M, false);

    pair<int, int> curr_pos = start_pos;

    while(true){

        int check_cnt = 0;

        int min_idx = -1;
        int min_dist = INT_MAX;

        for(int i=0; i<M; i++){

            if(check[i] == true){
                check_cnt++; continue;
            }

            else{

                pair<int, int> dest_pos = user_infos[i].start_pos;

                // cout << "dest_pos : "<< dest_pos.first << ", " << dest_pos.second << "\n";

                int dist = find_shorest_path(mat, curr_pos, dest_pos);

                // cout << "dist : "<< dist << "\n";


                if(dist < min_dist ){

                        min_dist = dist;
                        min_idx = i;

                }

                if(dist == min_dist){

                    if(user_infos[i].start_pos.first < user_infos[min_idx].start_pos.first){

                        min_idx = i;
                    }
                    else if(user_infos[i].start_pos.first == user_infos[min_idx].start_pos.first){

                        if(user_infos[i].start_pos.second < user_infos[min_idx].start_pos.second){

                            min_idx = i;

                        }


                    }


                }
            }
            
        }

        if (check_cnt == M) break;

        int dist_to_person = min_dist;

        fuel = fuel - min_dist;

        // cout << "curr fuel : " << fuel << "\n";

        if(fuel < 0) return -1;

        if(min_idx == -1){

            // cout << "error\n";
            return -1;
        }


        

        // 가장 가까운 person selected

        int dist_to_dest = find_shorest_path(mat, user_infos[min_idx].start_pos, user_infos[min_idx].destination_pos);
        check[min_idx] = true;
        curr_pos = user_infos[min_idx].destination_pos;

        fuel = fuel - dist_to_dest;


        if(fuel < 0) return -1;


        fuel = fuel + 2 * dist_to_dest;

        if(dist_to_person == -1 || dist_to_dest == -1) return -1;


        // cout << "total curr fuel : " << fuel << "\n";
    }

    return fuel;

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, F;
    
    
    cin >> N >> M >> F;

    vector<vector<int>> mat(N, vector<int> (N, -1));

    // shortest_dis.assign(N, vector<vector<int>>(N, vector<int>(2*M, -1)));

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){

            cin >> mat[i][j];

        }
    }

    pair<int, int> start_pos;

    cin >> start_pos.first >> start_pos.second;

    start_pos.first--;
    start_pos.second--;

    vector<user_info> user_infos(M);


    for(int i=0; i<M; i++){

        cin >> user_infos[i].start_pos.first >> user_infos[i].start_pos.second;
        cin >> user_infos[i].destination_pos.first >> user_infos[i].destination_pos.second;

        user_infos[i].start_pos.first--; user_infos[i].start_pos.second--;
        user_infos[i].destination_pos.first--; user_infos[i].destination_pos.second--;
    }


    int extra_fuel = driving(mat, user_infos, start_pos, F);
    // int extra_fuel = 0;

    cout << extra_fuel << "\n";

    return 0;
}