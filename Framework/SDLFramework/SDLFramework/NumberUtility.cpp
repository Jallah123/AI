#include "NumberUtility.h"
#include <random>

int NumberUtility::RandomNumber(int min, int max) 
{
	std::random_device dev;
	std::default_random_engine dre{ dev() };
	std::uniform_int_distribution<int> dist{ min, max };

	return dist(dre);
}

float NumberUtility::RandomNumber(float min, float max) 
{
	float retVal =  min + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (max - min)));
	return retVal;
}
