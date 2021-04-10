#include "Device.hpp"

#define NO_CHARACTERISTICS ((ULONG)0)
#define NOT_EXCLUSIVE ((BOOLEAN)FALSE)

Device::Device(const WdmDriver& driver, PUNICODE_STRING device_name, bool& result) :
    _device_object(create_device(driver.get(), device_name, result)),
    _symbolic_link(nullptr, device_name, result)
{
    _device_object->Flags |= DO_BUFFERED_IO;
    ClearFlag(_device_object->Flags, DO_DEVICE_INITIALIZING);
}

Device::~Device()
{
    if (_device_object != nullptr)
    {
        IoDeleteDevice(_device_object);
        _device_object = nullptr;
    }
}

PDEVICE_OBJECT Device::create_device(PDRIVER_OBJECT driver_object, PUNICODE_STRING device_name, bool& result)
{
    PDEVICE_OBJECT device_object = nullptr;

    /*CHECK_STATUS(*/IoCreateDevice(driver_object, 0, device_name, FILE_DEVICE_NULL, NO_CHARACTERISTICS, NOT_EXCLUSIVE, &device_object)/*)*/;

    result = true;

    return device_object;
}