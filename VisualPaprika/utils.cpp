#include"utils.hpp"

//stl
#include <stdio.h>
#include <math.h>

namespace visual_paprika
{
    void WriteBinaryInFile(char* vasmBinary)
    {
        //fopen_s()
        FILE* vasmData = fopen("bin.bin", "wb");
        fwrite(vasmBinary, 1, 512, vasmData);
        fclose(vasmData);
    }
}