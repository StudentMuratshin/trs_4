// trs_4.cpp : Defines the entry point for the application.
//

#include "trs_4.h"


int main()
{
	std::vector<int> N = { 100, 1000, 10000, 1000 };
	std::vector<int> M = { 10, 100, 1000, 10000 };

	auto n = N.begin();
	auto m = M.begin();

	const int a = 1;
	const double sigma = 0.3;

	for (; n != N.end() && m != M.end(); ++n, ++m)
	{
		vector < vector <double> > u(*n, vector <double>(*m));

		double tau = 1. / double(*n);
		double h = 1. / double(*m);

		for (int i = 0; i < *m; i++)
		{
			double x = i * h;
			u[0][i] = phi_0(x);
			u[1][i] = phi_1(x) * tau + u[0][i];
		}

		vector<double> A(*m);
		vector<double> B(*m);
		vector<double> C(*m);
		vector<double> f(*m);

		for (int i = 1; i < *m - 1; i++)
		{
			A[i] = -double(a) * sigma / h / h;
			B[i] = 1. / tau / tau + 2 * a * sigma / h / h;
			C[i] = -double(a) * sigma / h / h;
		}

		A[0] = 0;
		B[0] = -1. / h;
		C[0] = 1. / h;
		A[*m - 1] = 0;
		B[*m - 1] = 1.;
		C[*m - 1] = 0;


		for (int j = 2; j < *n; j++)
		{
			double t = j * tau;
			f[0] = ksi_0(t);
			for (int i = 1; i < *m - 1; i++)
			{
				double x = i * h;
				f[i] = 2 * u[j - 1][i] / tau / tau - u[j - 2][i] / tau / tau + a * (1 - 2 * sigma) / h / h * (u[j - 1][i+1] - 2*u[j - 1][i]
					+ u[j - 1][i-1]) + a * sigma / h / h * (u[j - 2][i + 1] - 2 * u[j - 2][i] + u[j - 2][i - 1]) + F(t, x);
			}
			f[*m - 1] = ksi_1(t);

			tridiagonal_matrix(*m, A, B, C, f, u[j]);

			u[j][0] = -ksi_0(t) * h + u[j][1];
			u[j][*m - 1] = ksi_1(t);
		}

		double diff, M = 0;
		for (int j = 0; j < *n; j++)
		{
			for (int i = 0; i < *m; i++)
			{
				diff = abs(u[j][i] - True_solve(j * tau, i * h));
				if (diff > M) {
					M = diff;

				}
				//cout << j * tau << "    " << i * h << "    " << M << endl;
				//cout << j * tau << "    " << i * h << "    " << u[j][i] << "   " << True_solve(j * tau, i * h) << endl;
			}
			//cout << endl;
			//if (j == 3) system("pause");
		}
		cout << "n: " << *n << "  m: " << *m << "  error:" << M << endl;
	}

	return 0;
}