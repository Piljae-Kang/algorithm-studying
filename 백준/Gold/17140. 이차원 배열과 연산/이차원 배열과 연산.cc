#include<bits/stdc++.h>
using namespace std;

int max_row_length = 0;
int max_column_length = 0;


void counting_sort(vector<int>& arr){

    vector<pair<int, int>> counting_arr;

    int prev_value = arr[0];
    counting_arr.push_back(make_pair(prev_value, 1));
    int index = 0;

    for(int i=1; i<arr.size(); i++){

        if(prev_value == arr[i]){

            counting_arr[index].second++;
        }
        else{

            
            counting_arr.push_back(make_pair(arr[i], 1));
            index++;
            prev_value = arr[i];

        }
    }


    // counting arr 정렬
    sort(counting_arr.begin(), counting_arr.end(), [](pair<int, int> a, pair<int, int> b){

        if(a.second == b.second){
            return a.first < b.first;
        }
        else{

            return a.second < b.second;
        }

    });

    vector<int> new_arr(2*counting_arr.size());


    for(int i=0; i<counting_arr.size(); i++){

        new_arr[2*i + 0] = counting_arr[i].first; 
        new_arr[2*i + 1] = counting_arr[i].second; 
    }

    // cout << "--------------------------\n";

    // for(int i=0; i<new_arr.size(); i++){

    //     cout << new_arr[i] << " ";
    // }

    // cout << "\n";
    // cout << "--------------------------\n";


    arr = move(new_arr);
}



void sort_by_line(vector<vector<int>>& mat, bool type){

    vector<vector<int>> new_mat (mat.size(), vector<int> (mat[0].size(), 0));

    if(type == true){ // R 연산 - 행 끼리

        for(int i=0; i<max_row_length; i++){

           vector<int> arr;


            for(int j=0; j<max_column_length; j++){

                int value = mat[i][j];

                if(value == 0) continue;

                arr.push_back(mat[i][j]);  
            } // line 마다 vector 만듦. 

            sort(arr.begin(), arr.end());

            counting_sort(arr);

            for(int j=0; j<arr.size(); j++){

                if(j >= 100){
                    break;
                }

                new_mat[i][j] = arr[j];
            }

            if (max_column_length < arr.size() && max_column_length <= 100) max_column_length = arr.size();


        }


        mat = move(new_mat);


    }
    else{ // C연산




        for(int i=0; i<max_column_length; i++){

            vector<int> arr;
 
 
             for(int j=0; j<max_row_length; j++){
 
                 int value = mat[j][i];
 
                 if(value == 0) continue;
 
                 arr.push_back(mat[j][i]);  
             } // line 마다 vector 만듦. 
 
             sort(arr.begin(), arr.end());
 
             counting_sort(arr);
 
             for(int j=0; j<arr.size(); j++){
 
                 if(j >= 100){
                     break;
                 }
 
                 new_mat[j][i] = arr[j];
             }
 
             if (max_row_length < arr.size() && max_row_length <= 100) max_row_length = arr.size();
 
 
         }
 
 
         mat = move(new_mat);

    }
}


void print_mat(vector<vector<int>>& mat){


    for(int i=0; i<max_row_length; i++){
        
        for(int j=0; j<max_column_length; j++){

            cout << mat[i][j] << " ";
        
        }

        cout << "\n";

    }



}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c, k;

    cin >> r >> c >>k;

    vector<vector<int>> mat(100, vector<int> (100, 0)); // 100 x 100

    max_row_length = 3;
    max_column_length =3;   


    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){

            cin >> mat[i][j];
        }
    }


    // sort_by_line(mat, false);
    // print_mat(mat);


    for(int i=0; i<102; i++){

        if(i == 101){

            cout << -1 << "\n";
            break;
        }


        if(mat[r-1][c-1] == k){

            cout << i << "\n";
            break;
        }

        else{

            if(max_row_length >= max_column_length){

                sort_by_line(mat, true);

            }
            else{

                sort_by_line(mat, false);

            }


        }

    }



    return 0;
}