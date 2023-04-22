// trs_4.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

constexpr auto pi = 3.14159265358979323846;

double F(double t, double x)
{
	//return sin(x);
	return 6;
}

double True_solve(double t, double x)
{
	return (2 * t + x) * (2 * t + x);
	//return 1 - (sin(x) * cos(3 * t) - sin(x)) / 9. + t;
}

double phi_0(double x)
{
	return x * x;
	//return 1;
}

double phi_1(double x)
{
	return 4 * x;
	//return 1;
}

double ksi_0(double t)
{
	return 4 * t;
	//return 1;
}

double ksi_1(double t)
{
	return (2 * t + 1) * (2 * t + 1);
	//return (-cos(3 * t) + 1) / 9.;
}

void tridiagonal_matrix(const int n, const vector<double>& A, const vector<double>& B, const vector<double>& C, const vector<double>& D, vector<double>& X) {
	vector<double> P(n - 1);
	vector<double> Q(n);

	// forward
	P[0] = C[0] / B[0];
	Q[0] = D[0] / B[0];
	for (int i = 1; i < n; ++i) {
		if (i < n - 1) P[i] = C[i] / (B[i] - A[i] * P[i - 1]);
		Q[i] = (D[i] - A[i] * Q[i - 1]) / (B[i] - A[i] * P[i - 1]);
	}

	//backward
	X[n - 1] = Q[n - 1];
	for (int i = n - 2; i >= 0; --i) {
		X[i] = Q[i] - P[i] * X[i + 1];
	}
}

// TODO: Reference additional headers your program requires here.
