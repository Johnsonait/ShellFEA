#pragma once

#include <vector>

class Element
{
private:
public:
	std::vector<std::vector<double>>* nodes;
	std::vector<int>* node_ids;
	static const uint64_t type;

	Element();
	Element(std::vector<std::vector<double>>* n, std::vector<int>* n_id);
	~Element() = default;

	virtual double ShapeFunction(const uint64_t& n_id, const double& s, const double& t) = 0;
	virtual double ShapeDerivative(const uint64_t& n_id, const uint64_t& dir, const double& s, const double& t) = 0;

	virtual double Jacobian(const double& s, const double& t) = 0;
	virtual std::vector<std::vector<double>> Derivatives(const double& s, const double& t) = 0;
};

