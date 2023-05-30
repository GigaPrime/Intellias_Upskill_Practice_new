#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "ImageProcessor.h"

typedef struct ResultOutput Result;
// typedef pointer Result Result to the Result struct
// and method destroyResult
// result isSuccess
// result waitForImage
// result ...

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

// separate to h and cpp files + forward declaration
// destroyResult function (new/delete)
// Result has std::future inside with the picture itself