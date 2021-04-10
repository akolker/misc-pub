#include "Win.h"

void* operator new(SIZE_T size_in_bytes);
void* operator new[](SIZE_T size_in_bytes);

void operator delete(void* address);
void operator delete(void* address, UINT64 tag);
void operator delete[] (void* address);