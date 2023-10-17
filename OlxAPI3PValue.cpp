#include "OlxAPI3PValue.h"

OlxAPI3PValue::OlxAPI3PValue(double* real, double* imag)
{
	phase[0] = complex<double>(real[0], imag[0]);
	phase[1] = complex<double>(real[1], imag[1]);
	phase[2] = complex<double>(real[2], imag[2]);

	sequence[0] = phase[0] + phase[1] + phase[2];
	sequence[1] = phase[0] + alpha * phase[1] + alpha * alpha * phase[2];
	sequence[2] = phase[0] + alpha * phase[2] + alpha * alpha * phase[1];
}

complex<double> OlxAPI3PValue::getPosSeq()
{
	return sequence[1];
}

complex<double> OlxAPI3PValue::getNegSeq()
{
	return sequence[2];
}

complex<double> OlxAPI3PValue::getZeroSeq()
{
	return sequence[0];
}

complex<double> OlxAPI3PValue::getA()
{
	return phase[0];
}

complex<double> OlxAPI3PValue::getB()
{
	return phase[1];
}

complex<double> OlxAPI3PValue::getC()
{
	return phase[2];
}
