#include "NumberUtility.h"
#include <random>


NumberUtility::NumberUtility()
{
}

int NumberUtility::GenerateRandomNumber(int min, int max)
{
	std::random_device dev;
	std::default_random_engine dre{ dev() };
	std::uniform_int_distribution<int> dist{ min, max };
	
	return dist(dre);
}


NumberUtility::~NumberUtility()
{
}
