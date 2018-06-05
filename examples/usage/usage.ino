// Example usage for athomdevice library by SpecialCircumstances.

#include "athomdevice.h"

// Initialize objects from the lib
Athomdevice athomdevice;

void setup() {
    // Call functions on initialized library objects that require hardware
    athomdevice.begin();
}

void loop() {
    // Use the library's initialized objects and functions
    athomdevice.process();
}
