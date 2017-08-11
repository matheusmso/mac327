#include <bits/stdc++.h>
using namespace std;

string ans[] = {"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y",
    "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x",
    "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};
long double x, y, z, num[12];

int main() {
    cin >> x >> y >> z;
    num[0] = powl(y,z)*log(x);
    num[1] = powl(z,y)*log(x);
    num[3] = num[2] = z*y*log(x);
    num[4] = powl(x,z)*log(y);
    num[5] = powl(z,x)*log(y);
    num[7] = num[6] = x*z*log(y);
    num[8] = powl(x,y)*log(z);
    num[9] = powl(y,x)*log(z);
    num[11] = num[10] = x*y*log(z);
    int k = 0;
    for (int i = 1; i < 12; i++)
        if (num[k] < num[i])
            k = i;
    cout << ans[k] << endl;
    return 0;
}
