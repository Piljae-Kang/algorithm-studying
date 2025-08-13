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

    std::vector<int> v(n);

    for (int i=0; i<n; i++){

        std::cin >> v[i];
    }

    int B, C;

    std::cin >> B >> C;

    long long total = 0;

    for (int num : v){

        num -= B;

        total++;    

        if (num>0){

            if (num % C != 0){

                total += (num / C + 1);

            }else{

                total += (num / C);

            }


        }
        else continue;


    }

    std::cout << total << "\n";


    return 0;
}