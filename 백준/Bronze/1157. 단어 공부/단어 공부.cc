#include <bits/stdc++.h>

void fast_io() {
    std::ios::sync_with_stdio(false);
    
    std::cin.tie(NULL); 
    std::cout.tie(NULL);
}


int main(){

    fast_io();
    
    std::string str;
    std::cin >> str;

    std::unordered_map<char, int> wordCount;


    for (int i=0; i<str.length(); i++){


        char ch = std::toupper(str[i]);

        if (wordCount.find(ch) == wordCount.end()){

            wordCount[ch] = 1;

        } 
        else {

            wordCount[ch] += 1;

        }

    }


    int max_cnt = 0;
    char max_key;
    bool dup_flag = false;

    for (auto& pair : wordCount){

        if(pair.second > max_cnt){
            max_key = pair.first;
            dup_flag = 0;
            max_cnt = pair.second;
        }
        else if (pair.second == max_cnt){

            dup_flag = true;
        }
    }

    if (dup_flag == true){

        std::cout << "?" << std::endl;
    }
    else {

        std::cout << max_key << std::endl;
    }


    return 0;

}