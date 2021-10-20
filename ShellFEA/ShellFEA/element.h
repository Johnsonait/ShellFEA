#pragma once

#include <vector>

class Element
{
private:
public:
	std::vector<double>* nodes;
	std::vector<int>* node_ids;

	Element();
	Element(std::vector<double>* n, std::vector<int>* n_id);
	~Element() = default;

	virtual double ShapeFunction(int n_id, const double& zeta, const double& eta, const double& mu) = 0;
	virtual double ShapeDerivative(int n_id, int dir, const double& zeta, const double& eta, const double& mu) = 0;

	virtual double Jacobian(const double& zeta, const double& eta,const double& mu) = 0;
	virtual std::vector<std::vector<double>> Derivatives(const double& zeta, const double& eta, const double& mu) = 0;
};

