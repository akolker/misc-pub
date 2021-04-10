#pragma once
#include "WdmDriver.hpp"
#include "Win.h"

class MementoDriver final : public WdmDriver
{
public:
    explicit MementoDriver(PDRIVER_OBJECT driver_object);

private:
    static NTSTATUS DispatchDeviceControl(PDEVICE_OBJECT DeviceObject, PIRP Irp);
};