#include "random.h"


RandomNumbers::RandomNumbers(unsigned long int s)
:seed(s)
{
	if(seed == 0)
	{
		std::random_device rd ;
		seed = rd();
	}

	rng = std::mt19937(seed);
}

double RandomNumbers::uniform_double(double lower, double upper)
{
	std::uniform_real_distribution<double> unif(lower, upper);
	return unif(rng);
}

void RandomNumbers::uniform_double(std::vector<double>& vec, double lower, double upper)
{
	std::uniform_real_distribution<double> unif(lower, upper);
	for(auto& number : vec)
	{
		number=unif(rng) ;
	}
}

void RandomNumbers::normal(std::vector<double>& vec, double mean, double sd)
{
	std::normal_distribution<double> normal(mean , sd);
    for(auto& number : vec)
	{
		number=normal(rng) ;
	}
}
	
double RandomNumbers::normal(double mean, double sd)
{
	std::normal_distribution<double> normal(mean , sd);
    return  normal(rng) ;
}

void RandomNumbers::poisson(std::vector<int>& vec, double mean)
{
	std::poisson_distribution<int> distribution(mean);
	for(auto& number : vec)
	{
		number=distribution(rng) ;
	}
}

int RandomNumbers::poisson(double mean)
{
	std::poisson_distribution<int> distribution(mean);
	
	return distribution(rng) ;
}


