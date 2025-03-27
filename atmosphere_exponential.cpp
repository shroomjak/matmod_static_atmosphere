#include "atmosphere_exponential.h"

atmosphere_exponential::atmosphere_exponential(double baseDensity, double basePressure, double gravity):
    model_atmosphere(baseDensity, basePressure, gravity),
    altitudeBands(28),
    refHeight(nullptr),
    refDensity(nullptr),
    scaleHeight(nullptr)
{
    set_constants();
}

atmosphere_exponential::~atmosphere_exponential()
{
    delete[] scaleHeight;
    delete[] refHeight;
    delete[] refDensity;
}

void atmosphere_exponential::set_constants(){
    refHeight = new double[altitudeBands];
    scaleHeight = new double[altitudeBands];
    refDensity = new double[altitudeBands];

    // The following assignments contain the data in the table in Vallado,
    // p. 534.  These values are identical to the nominal values in Wertz p. 820.
    refHeight[0]    = 0.0;
    refDensity[0]   = 1.225;
    scaleHeight[0]  = 7.249;
    refHeight[1]    = 25.0;
    refDensity[1]   = 3.899e-2;
    scaleHeight[1]  = 6.349;
    refHeight[2]    = 30.0;
    refDensity[2]   = 1.774e-2;
    scaleHeight[2]  = 6.682;
    refHeight[3]    = 40.0;
    refDensity[3]   = 3.972e-3;
    scaleHeight[3]  = 7.554;
    refHeight[4]    = 50.0;
    refDensity[4]   = 1.057e-3;
    scaleHeight[4]  = 8.382;
    refHeight[5]    = 60.0;
    refDensity[5]   = 3.206e-4;
    scaleHeight[5]  = 7.714;
    refHeight[6]    = 70.0;
    refDensity[6]   = 8.770e-5;
    scaleHeight[6]  = 6.549;
    refHeight[7]    = 80.0;
    refDensity[7]   = 1.905e-5;
    scaleHeight[7]  = 5.799;
    refHeight[8]    = 90.0;
    refDensity[8]   = 3.396e-6;
    scaleHeight[8]  = 5.382;
    refHeight[9]    = 100.0;
    refDensity[9]   = 5.297e-7;
    scaleHeight[9]  = 5.877;
    refHeight[10]   = 110.0;
    refDensity[10]  = 9.661e-8;
    scaleHeight[10] = 7.263;
    refHeight[11]   = 120.0;
    refDensity[11]  = 2.438e-8;
    scaleHeight[11] = 9.473;
    refHeight[12]   = 130.0;
    refDensity[12]  = 8.484e-9;
    scaleHeight[12] = 12.636;
    refHeight[13]   = 140.0;
    refDensity[13]  = 3.845e-9;
    scaleHeight[13] = 16.149;
    refHeight[14]   = 150.0;
    refDensity[14]  = 2.070e-9;
    scaleHeight[14] = 22.523;
    refHeight[15]   = 180.0;
    refDensity[15]  = 5.464e-10;
    scaleHeight[15] = 29.740;
    refHeight[16]   = 200.0;
    refDensity[16]  = 2.789e-10;
    scaleHeight[16] = 37.105;
    refHeight[17]   = 250.0;
    refDensity[17]  = 7.248e-11;
    scaleHeight[17] = 45.546;
    refHeight[18]   = 300.0;
    refDensity[18]  = 2.418e-11;
    scaleHeight[18] = 53.628;
    refHeight[19]   = 350.0;
    refDensity[19]  = 9.518e-12;
    scaleHeight[19] = 53.298;
    refHeight[20]   = 400.0;
    refDensity[20]  = 3.725e-12;
    scaleHeight[20] = 58.515;
    refHeight[21]   = 450.0;
    refDensity[21]  = 1.585e-12;
    scaleHeight[21] = 60.828;
    refHeight[22]   = 500.0;
    refDensity[22]  = 6.967e-13;
    scaleHeight[22] = 63.822;
    refHeight[23]   = 600.0;
    refDensity[23]  = 1.454e-13;
    scaleHeight[23] = 71.835;
    refHeight[24]   = 700.0;
    refDensity[24]  = 3.614e-14;
    scaleHeight[24] = 88.667;
    refHeight[25]   = 800.0;
    refDensity[25]  = 1.170e-14;
    scaleHeight[25] = 124.64;
    refHeight[26]   = 900.0;
    refDensity[26]  = 5.245e-15;
    scaleHeight[26] = 181.05;
    refHeight[27]   = 1000.0;
    refDensity[27]  = 3.019e-15;
    scaleHeight[27] = 268.00;
}

int atmosphere_exponential::FindBand(double height) const
{
    int index = altitudeBands - 1;
    for (int i = 0; i < altitudeBands - 1; ++i)
    {
        if (height < refHeight[i+1])
        {
            index = i;
            break;
        }
    }
    return index;
}

double atmosphere_exponential::getDensity(double position, double time) const
{
    if (position < 0.0)
        throw std::runtime_error("Altitude is below zero");
    double alt_km = position / 1000.0;
    int band = FindBand(alt_km);
    double density = refDensity[band] * std::exp( -(alt_km - refHeight[band]) / scaleHeight[band] );
    return density;
}
