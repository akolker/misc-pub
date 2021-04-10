#include "MementoDriver.hpp"

MementoDriver::MementoDriver(PDRIVER_OBJECT driver_object) : 
    WdmDriver(driver_object)
{
    register_dispatch(IRP_MJ_DEVICE_CONTROL, DispatchDeviceControl);
}

NTSTATUS MementoDriver::DispatchDeviceControl(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
    UNREFERENCED_PARAMETER(DeviceObject);
    UNREFERENCED_PARAMETER(Irp);

    PIO_STACK_LOCATION stack_location = IoGetCurrentIrpStackLocation(Irp);
    stack_location = stack_location;

    IoCompleteRequest(Irp, IO_NO_INCREMENT);

    return STATUS_SUCCESS;
}