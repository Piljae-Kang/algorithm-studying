#include <bits/stdc++.h>

void fast_io() {
    std::ios::sync_with_stdio(false);
    
    std::cin.tie(NULL); 
    std::cout.tie(NULL);
}


int main(){

    fast_io();
    
    std::string line;

    std::getline(std::cin, line);

    std::istringstream iss(line);

    std::string word;

    int cnt = 0;

    while(iss >> word){

        cnt++;

    }

    std::cout << cnt << std::endl;

    return 0;

}