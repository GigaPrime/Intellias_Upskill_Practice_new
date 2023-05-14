#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "ImageProcessor.h"

typedef struct ResultOutput Result;

struct ResultOutput 
{
    bool success;
};

ResultOutput* processTask(const char* imagePath, const char** operations) 
{
    ResultOutput* result = malloc(sizeof(ResultOutput));

    bool success = false /*some meaningful stuff here*/;

    result->success = success;
    return result;
}