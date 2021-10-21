#include "quad.h"

Quad::Quad(std::vector<std::vector<double>>* n, std::vector<int>* n_id, const double& t)
{
	nodes = n;
	node_ids = n_id;
	thickness = t;
}

double Quad::ShapeFunction(const uint64_t& n_id, const double& s, const double& t)
{
	return ((1 - SHAPE_PTS[n_id - 1][0] * s) * (1 - SHAPE_PTS[n_id - 1][1] * t)) / 4;
}

double Quad::ShapeDerivative(const uint64_t& n_id, const uint64_t& dir, const double& s, const double& t)
{
	switch (dir)
	{
	case 1:
		return (SHAPE_PTS[n_id - 1][0] * (1 + SHAPE_PTS[n_id - 1][1] * t)) / 4;
	case 2:
		return (SHAPE_PTS[n_id - 1][1] * (1 + SHAPE_PTS[n_id - 1][0] * s)) / 4;
	default:
		break;
	}
	return 0;
}

double Quad::JCalc(double& x_s, double& x_t, double& y_s, double& y_t, const double& s, const double& t)
{
	for (int m = 0; m < nodes->size(); ++m)
	{
		double N_s = ShapeDerivative(m, 1, s, t);
		double N_t = ShapeDerivative(m, 2, s, t);
		x_s += (*nodes)[m][0] * N_s;
		x_t += (*nodes)[m][0] * N_t;
		y_s += (*nodes)[m][1] * N_s;
		y_t += (*nodes)[m][1] * N_t;
	}
	return (x_s * y_t) - (x_t * y_s);
}

double Quad::Jacobian(const double& s, const double& t)
{
	double  x_s = 0, x_t = 0, y_s = 0, y_t = 0;

	return JCalc(x_s, x_t, y_s, y_t, s, t);
}

std::vector<std::vector<double>> Quad::Derivatives(const double& s, const double& t)
{
	std::vector<std::vector<double>> ret = {};

	double x_s = 0, x_t = 0, y_s = 0, y_t = 0;
	//Prepare function derivatives and jacobian
	double detJ = JCalc(x_s, x_t, y_s, y_t, s, t);
	//Use shape function derivatives and jacobians to find global derivatives for all nodes
	for (int m = 0; m < nodes->size(); ++m)
	{
		ret.push_back({});
		double N_s = ShapeDerivative(m, 1, s, t);
		double N_t = ShapeDerivative(m, 2, s, t);

		//Push in the given nodes global derivatives
		ret[m].push_back(((N_s*y_t)-(N_t*y_s))/detJ);
		ret[m].push_back(((N_t*x_s)-(N_s*x_t))/detJ);
	}
	return ret;
}

