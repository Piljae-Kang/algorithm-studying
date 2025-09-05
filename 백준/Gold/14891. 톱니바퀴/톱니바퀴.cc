#include<bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}


void rotate(deque<int>& dq, bool clockwise){

    if (clockwise){

        int tmp = dq.back();
        dq.pop_back();
        dq.push_front(tmp);

    }
    else{

        int tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp);

    }
}

void read_date(deque<int>& dq){

    string line;
    cin >> line;

    for(char ch : line){
        dq.push_back(ch - '0');
    }
}

void action(vector<deque<int>>& dq, int n_th, bool colorwise){


    // 자기 자신 rotate

    int left = dq[n_th][6];
    int right = dq[n_th][2];
    bool dir = colorwise;

    rotate(dq[n_th], dir);

    for(int i=n_th + 1; i < dq.size(); i++){

        int left_i = dq[i][6];
        int right_i = dq[i][2];

        if (right == left_i) break;

        else{

            if(dir) dir = false;
            else dir = true;

            right = dq[i][2];

            rotate(dq[i], dir);

        }
    }

    dir = colorwise;

    for (int i = n_th -1; i >=0; i--){

        int right_i = dq[i][2];

        if (left == right_i) break;

        else{

            if(dir) dir = false;
            else dir = true;

            left = dq[i][6];

            rotate(dq[i], dir);

        }

    }

}


void print_dq(vector<deque<int>>& dq){


    for (int i=0; i<dq.size(); i++){


        for(int j=0; j < dq[i].size(); j++){

            cout << dq[i][j] << " ";
        }

        cout << "\n";

    }

}

int scoring(vector<deque<int>> dq){

    int score = 0;

    for(int i=0; i<4; i++){

        if(dq[i][0] == 1) score += pow(2, i);

    }

    return score;
}


int main() {
    fastIO();

    vector<deque<int>> dq(4);

    read_date(dq[0]);
    read_date(dq[1]);
    read_date(dq[2]);
    read_date(dq[3]);

    int n;

    cin >> n;

    for(int i=0; i<n; i++){

        int n_th_dq, dir;

        cin >> n_th_dq >> dir;


        bool colorwise;
        if (dir == 1) colorwise = true;
        else colorwise = false;

        action(dq, n_th_dq - 1, colorwise);
        // print_dq(dq);

    }


    int score;
    score =  scoring(dq);

    cout << score << "\n";

    return 0;
}