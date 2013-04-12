#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;

void matrixChainOrder(int* p, int n) {
    int m[n][n];
    int s[n][n];
    for(int i = 0; i < n; i++) {
        m[i][i] = 0;
    }
    for(int l = 2; l <= n; l++) {
        for(int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for(int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    cout << m[1][n-1] << endl;
}

int main() {
    int size;
    cin >> size;
    while(size != 0) {
        int *p = new int[size+1];
        for(int i = 0; i < size+1; i++)
            cin >> p[i];
        matrixChainOrder(p, size+1);
        cin >> size;
    }
}

