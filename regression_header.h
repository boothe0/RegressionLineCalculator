/*
regression line testing
*/
#ifndef REGRESSION_HEADER_H
#define REGRESSION_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ARRAY_BUFFERS 1024


/* 
    Opening the file and copying data to X and Y arrays
    we want to skip the first column
    Data recieved from OpenAnalysis.org
    Returns: size of the data 
*/ 
int transposingXY(char *csv_file, float* arrayX, float* arrayY);

/*
    Computing the average 
    How to do it: Sum all points up in each array and divide by the length or total numbers in that arary
    sum * 1/n
    Returns: nothing
*/ 
void average(float* arrayX, float* arrayY, int arrayLength, float* averageX, float* averageY);

/*
    Computing the slope
    How to do it: Do the x1 - the average * y1 - the average / x1 - average squared and sum that up for all points
    Returns: nothing
*/
void slope(float* arrayX, float* arrayY, float averageX, float averageY, float *slope, int arrayLength);


/* Compute the intercept
    y = 0
    y = mx + b
    slope * x value
    b = y - mx
*/

float intercept(float slope, float averageX, float averageY);


// Print the regression line
float printRegressionLine(float slope, float intercept);


#endif 