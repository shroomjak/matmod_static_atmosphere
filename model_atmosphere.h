#ifndef MODEL_ATMOSPHERE_H
#define MODEL_ATMOSPHERE_H

#include "phys_model.h"

class model_atmosphere : public phys_model
{
    double * density;
public:
    model_atmosphere(double baseDensity, double basePressure, double gravity);
    virtual double getDensity(double position, double time) const = 0;
protected:
    double baseDensity, basePressure, gravity;
};

#endif // MODEL_ATMOSPHERE_H
