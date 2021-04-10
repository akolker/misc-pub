#pragma once
#include "WdmDriver.hpp"
#include "SymbolicLink.hpp"
#include "Win.h"

class Device final
{
public:
    Device(const WdmDriver& driver, PUNICODE_STRING device_name, bool& result);
    ~Device();

private:
    static PDEVICE_OBJECT create_device(PDRIVER_OBJECT driver_object, PUNICODE_STRING device_name, bool& result);

private:
    PDEVICE_OBJECT _device_object;
    SymbolicLink _symbolic_link;
};
