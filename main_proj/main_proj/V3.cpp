#include "Header.h"
void _V3(float* restrict pT, float* restrict pK, float* restrict pS0, float* restrict pC)
{
	int		i;
	float	d1, d2;
	float	erf1, erf2;

	for (i = 0; i < N; i++)
	{
		d1 = (logf(pS0[i] / pK[i]) + (r + sig * sig * 0.5f) *
			pT[i]) / (sig * sqrtf(pT[i]));
		d2 = (logf(pS0[i] / pK[i]) + (r - sig * sig * 0.5f) *
			pT[i]) / (sig * sqrtf(pT[i]));

		erf1 = 0.5f + 0.5f * erff(d1 / sqrtf(2.0f));
		erf2 = 0.5f + 0.5f * erff(d2 / sqrtf(2.0f));
		pC[i] = pS0[i] * erf1 - pK[i] * expf((-1.0f) * r *
			pT[i]) * erf2;
	}
}