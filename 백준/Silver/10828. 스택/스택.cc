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
    std::stack<int> s;

    for(int i=0; i<n; i++){
        std::string command;
        std::cin >> command;

        if (command == "push") {
            int num;
            std::cin >> num;
            s.push(num);
        } else if (command == "pop") {
            if (s.empty()) {
                std::cout << -1 << "\n";
            } else {
                std::cout << s.top() << "\n";
                s.pop();
            }
        } else if (command == "size") {
            std::cout << s.size() << "\n";
        } else if (command == "empty") {
            if (s.empty()) {
                std::cout << 1 << "\n";
            } else {
                std::cout << 0 << "\n";
            }
        } else if (command == "top") {
            if (s.empty()) {
                std::cout << -1 << "\n";
            } else {
                std::cout << s.top() << "\n";
            }
        }
    }

    return 0;
}