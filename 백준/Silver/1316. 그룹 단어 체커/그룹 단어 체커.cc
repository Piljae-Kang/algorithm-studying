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

    int cnt = 0;
    
    for(int i=0; i<n; i++){

        std::string word;
        std::cin >> word;
        char pre_ch = '\0';
        bool flag = true;

        std::set<char> s;

        int it = 0;

        for (char ch : word){

            if(pre_ch == '\0'){

                pre_ch = ch;
            }


            else if (pre_ch == ch){
                pre_ch = ch;
            }

            else if (pre_ch != ch){

                if(s.find(pre_ch) == s.end()){

                    s.insert(pre_ch);
                    pre_ch = ch;
                }
                else{

                    flag = false;
                    break;

                }

            }

            if(it == (word.size() -1)){


                if (s.find(ch) != s.end()){

                    flag = false;
                    break;
                }

            }

            it++;

        }

        if (flag) cnt++;



    }

    std::cout << cnt << "\n";

    return 0;
}