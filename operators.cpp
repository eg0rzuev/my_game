#include "MAIN_HEADER.h"


//new, new[], delete, delete [] operators overloaded
void* operator new[](size_t size, const char* func,  int line)
{
    void* ptr = calloc(1, size);
    fout << "New[] called in function "<< func << ", line is " << line << " \n";
    return ptr;
}

void* operator new(size_t size, const char* func,  int line)
{
    void* ptr = calloc(1, size);
    fout << "New called in function "<< func << ", line is " << line << " \n";
    return ptr;
}

void operator delete(void* p)   noexcept
{
    free(p);
}

void operator delete[](void* p) noexcept
{
    free(p);
}
