#include<bits/stdc++.h>

using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main(){

    fastIO();
    
    
    int n;
    cin >> n;

    priority_queue<int> max_heap;
    
    string str = "";


    for(int i=0; i<n; i++){

        int num;
        cin >> num;

        if (num==0){

            if(max_heap.empty()){

                str += "0\n";
            }
            else{

                str += to_string(max_heap.top()) + "\n";
                max_heap.pop();

            }
        }
        else{

            max_heap.push(num);
        }


    }

    cout << str;

    return 0;
}