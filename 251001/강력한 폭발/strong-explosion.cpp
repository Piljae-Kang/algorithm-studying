#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int n, m;
int grid[20][20];

void print_func(vector<vector<int>>& mat){

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){

            cout << mat[i][j] << " ";

        }
        cout << "\n";
    }
}

vector<pair<int, int>> pos;

int max_area = 0;

void action(vector<vector<int>>& mat, int bomb_idx, int depth){

    int pos_idx = depth - 1;

    int u = pos[pos_idx].first;
    int v = pos[pos_idx].second;

    if(bomb_idx == 1){

        for(int i=u-2; i <= u+2; i++){
            if(i<0 || i>= n) continue;
            mat[i][v] = 1;
        }

    }
    else if(bomb_idx == 2){

        for(int i=u-1; i <= u+1; i++){
            if(i<0 || i>= n) continue;
            mat[i][v] = 1;
        }

        for(int i=v-1; i <= v+1; i++){
            if(i<0 || i>= n) continue;
            mat[u][i] = 1;
        }

    }
    else if(bomb_idx == 3){

        for(int i=-1; i <=1; i++){
            if(u+i < 0 || u+i >= n || v+i >= n || v+i < 0) continue;
            mat[u+i][v+i] = 1;
        }

        for(int i=-1; i <=1; i++){
            if(u-i < 0 || u-i >= n || v+i >= n || v+i < 0) continue;
            mat[u-i][v+i] = 1;
        }

    }
}

int count_function(vector<vector<int>>& mat){

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mat[i][j] == 1) cnt++;
        }
    }

    return cnt;
}


void bomb(vector<vector<int>>& mat, int depth, int bomb_idx){


    if(depth > 0){
        action(mat, bomb_idx, depth);

		// cout << "------------------\n";
		// cout << "depth : " << depth << "bomb idx : " <<  bomb_idx << "\n";
		// print_func(mat); 
		// cout << "------------------\n";

		if(depth == m){

			max_area = max(max_area, count_function(mat));
			return ;
		}

    }

    for(int i=1; i<=3; i++){

        vector<vector<int>> tmp = mat;
        bomb(mat, depth + 1, i);

        mat = move(tmp);
    }


}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];

            if(grid[i][j] == 1){
                pos.push_back(make_pair(i, j));
            }
        }
    }

    m = pos.size();

    vector<vector<int>> mat(n, vector<int>(n, 0));

    bomb(mat, 0, 0);

    
    cout << max_area << "\n";

    return 0;
}
