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

	for (; n != N.end() && m != M.end(); ++n, ++m) 
	{
		vector < vector <double> > u(*n, vector <double>(*m));

		double tau = 1. / double(*n);
		double h = 1. / double(*m);

		//if (a * tau * tau / h / h > 1)
		//{
		//	cout << "DOLBAEB ONA NE USTOI4IVA"<< endl; 
		//	return 0;
		//}

		for (int i = 0; i < *m; i++)
		{
			double x = i * h;
			u[0][i] = phi_0(x);
			u[1][i] = phi_1(x) * tau + u[0][i];
		}

		for (int j = 2; j < *n; j++)
		{
			double t = j * tau;
			for (int i = 1; i < *m - 1; i++)
			{
				double x = i * h;
				u[j][i] = a * tau * tau * (u[j - 1][i + 1] - 2 * u[j - 1][i] + u[j - 1][i - 1]) / h / h + F(t, x) * tau * tau + 2 * u[j - 1][i] - u[j - 2][i];
			}
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
			//if (j == 3) system("pause");
		}
		cout << "n: " << *n  << "  m: " << *m << "  error:" << M << endl;
	}

	return 0;
}