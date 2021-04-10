#pragma once
#include "Win.h"

class WdmDriver
{
public:
    explicit WdmDriver(PDRIVER_OBJECT driver_object);
    virtual ~WdmDriver() = default;

public:
    PDRIVER_OBJECT get() const;

protected:
    bool register_dispatch(UINT32 major, DRIVER_DISPATCH dispatch_function);

private:
    static NTSTATUS DefaultDispatch(PDEVICE_OBJECT DeviceObject, PIRP Irp);

private:
    PDRIVER_OBJECT _driver_object;
};