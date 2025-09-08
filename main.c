#include "regression_header.h"

int main(){
    float arrayX[100];
    float arrayY[100];
    float averageX = 0;
    float averageY = 0;
    int dataPointsCount = 0;
    float slopeVal = 0;
    dataPointsCount = transposingXY("random_points.csv", arrayX, arrayY);
    average(arrayX, arrayY, dataPointsCount, &averageX, &averageY);
    slope(arrayX, arrayY, averageX, averageY, &slopeVal, dataPointsCount);
    float interceptVal = intercept(slopeVal, averageX, averageY);
    printRegressionLine(slopeVal, interceptVal);

}

