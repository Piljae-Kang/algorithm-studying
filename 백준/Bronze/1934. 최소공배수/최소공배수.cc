#include<bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// 재귀적 GCD (더 빠름)
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// 최소공배수 계산
int lcm(int a, int b) {
    if (a == 0 || b == 0) return 0;  // 예외 처리
    return (a / gcd(a, b)) * b;      // 오버플로우 방지
}

int main() {
    fastIO();
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        int result = lcm(a, b);
        cout << result << "\n";
    }
    
    return 0;
}