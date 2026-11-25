#include <stdio.h> 


#ifndef MAT_H
#define MAT_H

typedef struct complexe_s
{
    double reel;
    double im;
    double norme;
    double arg;
} Complexe;

Complexe cree_complexe(double r, double i);

double rad2deg(double a);

double deg2rad(double a);

#endif