#include "for_task_1.h"

int main()
{
	std::vector<int> N = { 1000 };
	std::vector<int> M = { 100 };

	const double c = 3.;

	auto n = N.begin();
	auto m = M.begin();

	for (; n != N.end() && m != M.end(); ++n, ++m)
	{
		double tau = 2. / double(*n);
		double h = 1. / double(*m);

		vector < vector <double> > u(*n, vector <double>(*m));

		for (int i = 0; i < *m; i++)
		{
			double x = i * h;
			u[0][i] = sin(3 * x);
		}

		for (int j = 0; j < *n; j++)
		{
			double t = j * tau;
			u[j][0] = t * t * t - sin(9 * t);
		}

		for (int j = 1; j < *n; j++)
		{
			double t = j * tau;
			for (int i = 1; i < *m; i++)
			{
				double x = i * h;
				u[j][i] = (c * tau / h * u[j][i - 1] + u[j - 1][i] + tau * f(x, t)) * h / (h + c * tau);
			}
		}

		double diff, M = 0;
		for (int j = 0; j < *n; j++)
		{
			for (int i = 0; i < *m; i++)
			{
				diff = abs(u[j][i] - sol(i * h, j * tau));
				if (diff > M) {
					M = diff;
					//cout << j * tau << "    " << i * h << "    " << M << endl;
				}
				//cout << j * tau << "    " << i * h << "    " << u[j][i] << "   " << sol(j * tau, i * h) << endl;
			}
			//if (j == 3) system("pause");
		}
		cout << "n: " << *n << "  m: " << *m << "  error:" << M << endl;

	}

	return 0;
}