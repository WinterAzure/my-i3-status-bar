#include "../globals.hxx"

#include <libusb-1.0/libusb.h>

inline const int get_devs(libusb_device **devs){
    static libusb_device *dev;
    static struct libusb_device_descriptor desc;
    int total = 0,i = 0;

    dev=NULL;
    while ((dev = devs[i++]) != NULL){
        if (libusb_get_device_descriptor(dev, &desc)<0) return -1;
        total++;
    }
    return total-DEFAULT_USB_DEVICES;
}

const g_data_st *module_usb_count(void){
    static libusb_device **devs;

    clean_g_data();
    if (libusb_init(NULL)<0||libusb_get_device_list(NULL,&devs)<0){
        ON_ERROR_SET_MARKUP("Error in module usb.");
        return &g_data;
    }

    g_data.full_text<<"USB Devices: "<<get_devs(devs);
    libusb_free_device_list(devs, 1);
    libusb_exit(NULL);
    return &g_data;
}