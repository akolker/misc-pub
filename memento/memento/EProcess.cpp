#include "EProcess.hpp"

EProcess::EProcess(UINT32 pid, bool& result) :
    _initialized(false)
{
    if(!result) 
    {
        goto cleanup;
    }
    
    result = false;
    
    /*CHECK_NTSTATUS(*/PsLookupProcessByProcessId(reinterpret_cast<HANDLE>(pid), &_eprocess)/*)*/;

    result = true;

cleanup:
    _initialized = result;
}

EProcess::~EProcess()
{
    if(_initialized)
    {
        ObDereferenceObject(_eprocess);
        _initialized = false;
    }
}

PEPROCESS EProcess::get() const
{
    return _eprocess;
}