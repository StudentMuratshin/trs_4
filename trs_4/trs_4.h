// trs_4.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

constexpr auto pi = 3.14159265358979323846;

double F(double t, double x)
{
	return 6;
}

double True_solve(double t, double x)
{
	return (2 * t + x) * (2 * t + x);
}

double phi_0(double x)
{
	return x * x;
}

double phi_1(double x)
{
	return 4 * x;
}

double ksi_0(double t)
{
	return 4 * t;
}

double ksi_1(double t)
{
	return (2 * t + 1) * (2 * t + 1);
}
// TODO: Reference additional headers your program requires here.
