#include "quad.h"

Quad::Quad(std::vector<double>* n, std::vector<int>* n_id)
{
	nodes = n;
	node_ids = n_id;
}

double Quad::Jacobian(const double& zeta, const double& eta, const double& mu)
{
	return 0;
}

std::vector<std::vector<double>> Quad::Derivatives(const double& zeta, const double& eta, const double& mu)
{
	std::vector<std::vector<double>> ret = {};
	return ret;
}

