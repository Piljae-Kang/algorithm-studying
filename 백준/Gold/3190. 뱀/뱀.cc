#include<bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

pair<int, int> next_snake_head(deque<pair<int, int>>& snake, int dir){

    pair<int, int> head_pos = snake.front();

    if(dir == 0){

        return make_pair(head_pos.first - 1, head_pos.second);
    }
    else if(dir == 1){

        return make_pair(head_pos.first, head_pos.second + 1);

    }
    else if(dir == 2){
        return make_pair(head_pos.first + 1, head_pos.second);

    }
    else{
        return make_pair(head_pos.first, head_pos.second - 1);
    }

}

bool check_collison(deque<pair<int, int>>& snake, int i, int j){

    for(pair<int, int> pos : snake){

        if(pos.first == i && pos.second == j) return true;

    }

    return false;
}


int snake_game(vector<vector<int>>& mat, unordered_map<int, string>& command, deque<pair<int, int>>& snake){

    int time = 0;
    int dir = 1;  // dir 0 : N, 1 : E, 2 : S, 3 : W

    while(true){

        time++;

        // printf("time : %d, dir : %d\n", time, dir);
        
        pair<int, int> next_snake_head_pos = next_snake_head(snake, dir);


        // printf("pos.x : %d, pos.y : %d\n", next_snake_head_pos.first, next_snake_head_pos.second);

        int i = next_snake_head_pos.first; int j = next_snake_head_pos.second;


        if(i < 0 || j < 0 || i>= mat.size() || j >= mat[0].size()){ // 범위 밖 제거
            break;
        }

        if(check_collison(snake, i, j)){ // 자기 몸이랑 부딫히면 제거
            break;
        }

        snake.push_front(next_snake_head_pos); // 머리 위치 update


        if(mat[i][j] == 1){ // 사과 발견 -> 꼬리는 가만히 있음

            mat[i][j] = 0;
        } 
        else{  // 사과 없음 -> 꼬리 삭제

            snake.pop_back();
        }



        if(command.find(time) != command.end()){

            if(command[time] == "D"){  //오른쪽으로 90도도

                dir = (dir + 1) % 4;
            }
            else{ // 왼쪽으로 90도 
 
                dir = (dir + 3) % 4; 
            }

        }

    }

    return time;
}

int main() {
    fastIO();

    int n, k;

    cin >> n;

    vector<vector<int>> mat(n, vector<int> (n, 0));

    cin >> k;

    // cout << "k : " << k << "\n";

    for(int i=0; i<k; i++){

        int x, y;

        cin >> x >> y;

        mat[x-1][y-1] = 1;
    }

    // vector<pair<int, string>> command;

    unordered_map<int, string> command;

    int c;

    cin >> c;

    // cout << "c : " << c << "\n";


    for(int i=0; i<c; i++){

        int t;
        string cmd;

        cin >> t >> cmd;

        command[t] = cmd;
    }


    deque<pair<int, int>> snake;
    snake.push_back(make_pair(0, 0));

    int time = snake_game(mat, command, snake);

    cout << time << "\n";

    return 0;
}