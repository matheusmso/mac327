#include <bits/stdc++.h>
using namespace std;

int n;
double x, y, X, Y, a, b, r;

double dist(double i, double j, double p, double q) {
	double h = p - i;
	double w = q - j;
	return sqrt((h*h)+(w*w));
}

int main() {
	scanf(" %d %lf", &n, &r);
	r = r*atan(1)*8;
	scanf(" %lf %lf", &X, &Y);
	a = X;
	b = Y;
	for (int i = 0; i < n-1; i++) {
		scanf(" %lf %lf", &x, &y);
		r += dist(X, Y, x, y);
		X = x;
		Y = y;
	}
	r += dist(X, Y, a, b);
	printf("%.2lf\n", r);
	return 0;
}