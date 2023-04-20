// trs_4.cpp : Defines the entry point for the application.
//

#include "trs_4.h"


int main()
{
	const int n = 5000;
	const int m = 1000;
	const int a = 1;

	vector < vector <double> > u(n, vector <double>(m));

	double tau = 1. / double(n);
	double h = 1. / double(m);

	for (int i = 0; i < m; i++)
	{
		double x = i * h;
		u[0][i] = phi_0(x);
		u[1][i] = phi_1(x) * tau + u[0][i];
	}

	for (int j = 2; j < n; j++)
	{
		double t = j * tau;
		for (int i = 1; i < m - 1; i++)
		{
			double x = i * h;
			u[j][i] = a * tau * tau * (u[j - 1][i + 1] - 2 * u[j - 1][i] + u[j - 1][i - 1]) / h / h + F(t, x) * tau * tau + 2 * u[j - 1][i] - u[j - 2][i];
		}
		u[j][0] = -ksi_0(t) * h - u[j][1];
		u[j][m - 1] = ksi_1(t);
	}

	double diff, M = 0;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < m; i++)
		{
			diff = abs(u[j][i] - True_solve(j * tau, i * h));
			if (diff > M) {
				M = diff;
				//cout << j * tau << " " << i * h << " " << M << endl;
			}
		}
	}
	cout << M << endl;
	return 0;
}