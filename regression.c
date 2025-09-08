#include "regression_header.h"


int transposingXY(char *csv_file, float* arrayX, float* arrayY){
    int floatArrIndx = 0;


    FILE *fp = fopen(csv_file, "r");

    if (!fp){
        printf("Cannot open file...");
    }
    
    else{
        char line[ARRAY_BUFFERS];

        int row = 0;

        while (fgets(line, ARRAY_BUFFERS, fp)){
            if (row == 0){
                row++;
                continue;
            }
            
            char* valueX;
            char* valueY;  
            char* ignored = strtok(line, ", ");

            valueX = strtok(NULL, ", ");
            valueY = strtok(NULL, ", ");


            if (valueX && valueY) {
                float x = strtof(valueX, NULL);
                float y = strtof(valueY, NULL);
                arrayX[floatArrIndx] = x;
                arrayY[floatArrIndx] = y;
                floatArrIndx++;
            }

            row++;
            
         }
        fclose(fp);
    }
    return floatArrIndx;
}


void average(float* arrayX, float* arrayY, int arrayLength, float* averageX, float* averageY){
    int sumX = 0;
    int sumY = 0;
    for(int i = 0; i < arrayLength; i++){
        sumX += arrayX[i];
        sumY += arrayY[i];
    }

    *averageX = (float)sumX/arrayLength;
    *averageY = (float)sumY/arrayLength;

}

void slope(float* arrayX, float* arrayY, float averageX, float averageY, float *slope, int arrayLength){
    float numerator = 0;
    float denom = 0;
    for(int i = 0; i < arrayLength; i++){
        // TODO Fix the calculation

        numerator += (arrayX[i] - averageX) * (arrayY[i] - averageY);
        denom += pow(arrayX[i] - averageX, 2) ;
    }
    *slope = numerator / denom;
}

// return intercept
float intercept(float slope, float averageX, float averageY){

    return averageY - slope * averageX;
}

float printRegressionLine(float slope, float intercept){
    printf("y = %fx + %f", slope, intercept);
}