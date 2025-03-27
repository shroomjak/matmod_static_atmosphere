#ifndef ATMOSPHERE_EXPONENTIAL_H
#define ATMOSPHERE_EXPONENTIAL_H

#include "model_atmosphere.h"
#include "grid_model.h"
#include "model_density.h"

class atmosphere_exponential : public model_atmosphere, grid_model, model_density
{
public:
    atmosphere_exponential(double baseDensity, double basePressure, double gravity);
    ~atmosphere_exponential();
    void set_constants();
    double getDensity(double position, double time=0.0) const override;
    int FindBand(double) const;
protected:
    double * scaleHeight, * refHeight, * refDensity;
    int altitudeBands;
};

#endif // ATMOSPHERE_EXPONENTIAL_H
