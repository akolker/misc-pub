#include "Runtime.hpp"

void* operator new(SIZE_T size)
{
    return ExAllocatePool(NonPagedPool, size);
}

void* operator new[](SIZE_T size)
{
    return operator new(size);
}

void operator delete(void* address)
{
    ExFreePool(address);
}

void operator delete(void* address, UINT64)
{
    operator delete(address);
}

void operator delete[](void* address) 
{
    operator delete(address);
}

