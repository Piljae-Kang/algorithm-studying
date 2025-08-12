#include <bits/stdc++.h>

void fast_io() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL); 
    std::cout.tie(NULL);
}

int special_ch(char ch){

    if (ch == '[') return 1;
    else if (ch == ']') return -1;
    else if (ch == '(') return 2;
    else if (ch == ')') return -2;
    else return 0;
}

int main(){
    fast_io();

    while(true){

        std::string line;
        std::getline(std::cin, line);

        if (line[0] == '.') break;

        std::stack<char> s;

        for(char ch : line){

            if (ch == '.'){

                if(s.empty()) std::cout << "yes" << "\n";
                else std::cout << "no" << "\n";

            }

            int type = special_ch(ch);
            if (type !=0){

                if (s.empty()) s.push(ch);
                else if (type == -1 || type == -2){

                    int top_type = special_ch(s.top());
                    if(type + top_type == 0) s.pop();
                    else s.push(ch);
                }
                else{
                    s.push(ch);

                }          
                


            }



        }

    }

    return 0;
}