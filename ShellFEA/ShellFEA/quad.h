#pragma once
#include "element.h"
class Quad :
    private Element
{
private:
    double thickness;
    static constexpr const double SHAPE_PTS[4][2] = { {-1,-1},{1,-1},{1,1},{-1,1} };

    double JCalc(double& x_s, double& x_t, double& y_s, double& y_t, const double& s, const double& t);
public:
    static const uint64_t type = 4;
    Quad() = default;
    Quad(std::vector<std::vector<double>>* n, std::vector<int>* n_id, const double& t);
    ~Quad() = default;

    double ShapeFunction(const uint64_t& n_id, const double& s, const double& t) override;
    double ShapeDerivative(const uint64_t& n_id, const uint64_t& dir, const double& s, const double& t) override;

    double Jacobian(const double& s, const double& t) override;
    std::vector<std::vector<double>> Derivatives(const double& s, const double& t) override;
};

