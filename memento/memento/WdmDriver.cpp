#include "WdmDriver.hpp"

WdmDriver::WdmDriver(PDRIVER_OBJECT driver_object) :
    _driver_object(driver_object)
{
    for (UINT32 index_of_function = 0; index_of_function < IRP_MJ_MAXIMUM_FUNCTION; index_of_function++)
    {
        driver_object->MajorFunction[index_of_function] = DefaultDispatch;
    }
}

NTSTATUS WdmDriver::DefaultDispatch(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
    UNREFERENCED_PARAMETER(DeviceObject);
    UNREFERENCED_PARAMETER(Irp);

    return STATUS_SUCCESS;
}

bool WdmDriver::register_dispatch(UINT32 major, DRIVER_DISPATCH dispatch_function)
{
    if (major >= IRP_MJ_MAXIMUM_FUNCTION)
    {
        return false;
    }

    _driver_object->MajorFunction[major] = dispatch_function;
    
    return true;
}

PDRIVER_OBJECT WdmDriver::get() const
{
    return _driver_object;
}