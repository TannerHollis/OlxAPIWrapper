#pragma once

#include <complex>

#define M_PI 3.141592653589793238

using namespace std;

/**
* This class yields the 3-Phase values of either current or voltage values, 
* results are of complex<double> type.
*/
class OlxAPI3PValue
{
public:
	OlxAPI3PValue(double* real, double* imag);

	complex<double> getPosSeq();

	complex<double> getNegSeq();

	complex<double> getZeroSeq();

	complex<double> getA();

	complex<double> getB();

	complex<double> getC();

private:
	const complex<double> alpha = complex<double>(1.0, 2.0 / 3.0 * M_PI);

	complex<double> phase[3];
	complex<double> sequence[3];
};

