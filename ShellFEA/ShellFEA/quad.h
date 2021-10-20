#pragma once
#include "element.h"
class Quad :
    private Element
{
private:

public:
    Quad() = default;
    Quad(std::vector<double>* n, std::vector<int>* n_id);
    ~Quad() = default;

    double Jacobian(const double& zeta, const double& eta, const double& mu) override;
    std::vector<std::vector<double>> Derivatives(const double& zeta, const double& eta, const double& mu) override;
};

