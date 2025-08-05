#include <bits/stdc++.h>

void fast_io() {
    std::ios::sync_with_stdio(false);
    
    std::cin.tie(NULL); 
    std::cout.tie(NULL);
}

int main(){

    fast_io();

    int n;

    std::cin >> n;

    int total = 0;
    int max_score = INT_MIN;

    for(int i=0; i<n;i++){

        int score;
        std::cin >> score;
        
        if(score > max_score){

            max_score = score;

        }

        total += score;
    }

    double avg_score = total * 100 / double(max_score) / n;

    std::cout << avg_score << std::endl;

    return 0;

}