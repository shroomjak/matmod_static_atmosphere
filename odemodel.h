#ifndef ODEMODEL_H
#define ODEMODEL_H

#include "model.h"

class odemodel : public model
{
private:
    std::vector<double> _state;
public:
    odemodel();

    std::vector<double> rightPart(double t, std::vector<double> x);
};

#endif // ODEMODEL_H
