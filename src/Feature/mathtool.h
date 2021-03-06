//
//  mathtool.h
//  SpeechRecongnitionSystem
//
//  Created by Admin on 9/11/14.
//  Copyright (c) 2014 Admin. All rights reserved.
//

#ifndef __SpeechRecongnitionSystem__mathtool__
#define __SpeechRecongnitionSystem__mathtool__

#include <iostream>
#include <complex>

const double PI = std::acos(-1);

typedef std::complex<double> cp;

void dft(cp *a,int n,int f);
void fft(cp *a,int n,int f);
//size(a) > 2*n
void dct(double *a,int n,int f);
void dct2(double *a, int n);

// -log(x+y)  a = -log(x) b = -log(y)
double logInsideSum(double a, double b);

// -log((abs(x-y))  a = -log(x) b = -log(y)
double logInsideDist(double a, double b);

double p2cost(double p);

double cost2p(double cost);

#define e 2.718281828459
#endif /* defined(__SpeechRecongnitionSystem__mathtool__) */
