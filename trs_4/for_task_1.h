#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

constexpr auto pi = 3.14159265358979323846;

double sol(double x, double t)
{
	return t * t * t - t * t * x + sin(3 * x - 9 * t);
}

double f(double x, double t)
{
	return -2 * t * x;
}