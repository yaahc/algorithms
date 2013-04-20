#include <iostream>
#include <stack>
#include <float.h>

using namespace std;

double calc_error(double * X, double * Y, int i, int j) {
    double sum = 0;
    double a;
    double sum_xy = 0;
    double sum_x = 0;
    double sum_y = 0;
    double sum_xx = 0;
    int num = j - i + 1;
    for(int ii = i; ii <= j; ii++) {
        //cout << X[ii] << " " << Y[ii] << " " << ii << " ";
        sum_xy += X[ii]*Y[ii];
        sum_x += X[ii];
        sum_y += Y[ii];
        sum_xx += X[ii]*X[ii];
    }
    //cout << endl;
    a = (num*sum_xy - sum_x*sum_y)/(num*sum_xx - sum_x*sum_x);
    double b;
    b = (sum_y - a*sum_x)/num;
    for(int ii = i; ii <= j; ii++) {
        sum += (Y[ii] - (a*X[ii] + b))*(Y[ii] - (a*X[ii] + b));
    }
    //cout << sum << " ";
    return sum;
}

double segLSQ(double * X, double * Y, int num, double cost) {
    double r[num];
    int s[num];
    double e[num][num];
    r[0] = 0;
    for(int j = 1; j <= num; j++) {
        for(int i = 1; i < j; i++) {
            e[i][j] = calc_error(X, Y, i, j); //compute the least squares error  for the segment pi,..,pj
            //cout << i << "," << j << ":" << e[i][j] << " ";
        }
        //cout << endl;
    }
    for(int j = 1; j <= num; j++) {
        double q = DBL_MAX;
        for(int i = 1; i <= j; i++) {
            //cout << e[i][j] << " " << cost << " " << r[i-1] << " ";
            if(q > e[i][j]+cost+r[i-1]) {
                q = e[i][j] + cost + r[i-1];
                s[j] = i;
            }
        }
        r[j] = q;
        //cout << "s[" << j << "] = " << s[j] << endl;
        //cout << "r[" << j << "] = " << q << endl;
    }
    //print solution
    int n = num;
    stack<int> mystack;
    while(n > 1) {
        mystack.push(s[n]);
        n = s[n];
    }
    while(!mystack.empty()) {
        cout << mystack.top() << endl;
        mystack.pop();
    }
    return 0;
    //return r and s;
}

int main() {
    double * X;
    double * Y;
    int num;
    double cost;
    cin >> num;
    while(num != 0) {
        cin >> cost;
        X = new double[num+1];
        Y = new double[num+1];
        for(int i = 1; i <= num; i++) {
            cin >> X[i];
            cin >> Y[i];
        }
        segLSQ(X,Y,num,cost);
        cin >> num;
        delete [] X;
        delete [] Y;
    }
    return 0;
}
