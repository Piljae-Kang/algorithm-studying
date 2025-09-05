#include<bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


bool check_road(vector<int>& road, int L){

    int plane_cnt = 1;

    for(int i=0; i<road.size() - 1; i++){

        int cur_h = road[i];
        int next_h = road[i+1];

        int gap = cur_h - next_h;

        if (abs(gap) > 1) return false; // cannot use;

        else if(gap == 0){ // road

            plane_cnt++;
        }
        else{ // should use it

            if (gap > 0){ // 내리막길

                // cout << " before i : " << i << "\n";

                for (int j = 2; j <=L; j++){

                    if ((i+j) >= road.size()) return false;
 
                    if (next_h != road[i + j]) return false;
                }

                i += L -1;

                // cout << " after i : " << i << "\n";

                plane_cnt = 0;

            }
            else { // 오르막길

                if (plane_cnt < L) return false;


                plane_cnt = 1;
    
            }
        

        }


    }

    return true;

}



int main() {
    fastIO();


    int n, L;
    cin >> n >> L;

    vector<vector<int>> mat_row (n, vector<int> (n));
    vector<vector<int>> mat_col (n, vector<int> (n));

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){

            int value;
            cin >> value;

            mat_row[i][j] = value;
            mat_col[j][i] = value;

        }
    }


    bool c = check_road(mat_col[4], L);

    int cnt = 0;

    for(int i=0; i<n; i++){

        if (check_road(mat_row[i], L)){

            // cout << i << "\n";

            cnt++;
        } 
    }


    for(int i=0; i<n; i++){

        if (check_road(mat_col[i], L)){

            // cout << i << "\n";

            cnt++;

        } 
    }


    cout << cnt << "\n";

    return 0;
}