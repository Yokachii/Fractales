#include "../include/mat.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>


Complexe cree_complexe(double r, double i){
    double n = sqrt(r*r + i*i);
    double arg = atan(i/r);
    Complexe res = {r,i,n,arg};
    return res;
}

double rad2deg(double a){
    return a*180/M_PI;
}

double deg2rad(double a){
    return a*M_PI/180;
}

