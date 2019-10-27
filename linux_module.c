#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/usb.h>
#include<linux/usb/hcd.h>
#include<libusb-1.0/libusb.h>

MODULE_LICENSE("GPL");

//Initializing module
int usb_boot_init(void) {
    //message printed
    printk(KERN_INFO "USB Boot module initialised");

    //Listing of usb devices
    int chix = 0;
    //Required ID;
    bool flag = false;
    struct usb_device *dev,*childdev = NULL;
    struct usb_bus *bus = NULL;

    //hardcode the needed productID or vendorID
    __le16 deviceID = 0;
    __le16 prodID = 0;

    lists_for_each_entry(bus,&usb_bus_list,bus_list) {
        printk("\n USB Bus : %d",bus->busnum);
    
        dev = bus->root_hub;
        printk("\n Vendor ID : %x, Product ID: %x\n",dev->descriptor.idVendor, dev->descriptor.idProduct);
        if(dev->descriptor.idProduct == prodID) {
            flag = true;
            printk("Found the U")
        }
        usb_hub_for_each_child(dev,chix,childdev) {
            if(childdev) {
                printk("\n Vendor ID : %x, Product ID: %x\n",childdev->descriptor.idVendor, childdev->descriptor.idProduct);
                if(dev->descriptor.idProduct == prodID) {
                    flag = true;
                    printk("Found the U")
                }
            }       
        }
    }

    if(!flag) {
        printk("USB Not found...\n SHUTINGDOWN");
        //invoking the shutting down system call
                
    }
    return 0;
}

void usb_boot_exit(void) {
    printk(KERN_INFO "USB Boot module exiting");
    return;
}

module_init(usb_boot_init);
module_exit(usb_book_exit);

