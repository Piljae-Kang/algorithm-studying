#include<bits/stdc++.h>

using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){

    fastIO();
    
    int case_N;
    cin >> case_N;


    for(int i=0; i<case_N; i++){

        string line;
        string command;
        string size;

        cin >> command;
        cin >> size;
        cin >> line;

        line = line.substr(1, line.size() - 2);


        stringstream sst(line);
        string token;

        // vector<int> v;
        deque<int> dq;

        
        while(getline(sst, token, ',')){

            if (token.size() > 0) dq.push_back(stoi(token));
        }

        int arr_size = stoi(size);

        int R_n = 0;

        bool error_flag = false;

        for(const auto& cd : command){

            if (cd == 'R'){

                R_n++;

            }
            else{

                if(dq.empty()){

                    error_flag = true;
                    break;
                }

                if(R_n % 2 ==0){ // 순서 그대로

                    dq.pop_front();

                }
                else{ // 역전
                    dq.pop_back();

                }

            }


        }

        if (error_flag){

            cout << "error" <<"\n";
            continue;

        }

        string result = "[";
        if (R_n % 2 == 0) {
            for(auto it = dq.begin(); it != dq.end(); ++it) {
                if(it != dq.begin()) result += ",";
                result += to_string(*it);
            }
        } else {
            for(auto it = dq.rbegin(); it != dq.rend(); ++it) {
                if(it != dq.rbegin()) result += ",";
                result += to_string(*it);
            }
        }
        result += "]";
        cout << result << "\n";


    }



    return 0;
}