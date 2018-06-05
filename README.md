# athomdevice

A Particle library for simple integration into Athom Homey home automation. If you want more information on Particle devices go to [Particle](https://particle.io), or if you want to know more about Athom Homey then [Athom Homey](https://athom.com)

## Getting Started

NB: Work in Progress

You'll need a Homey to make much use of this, so assuming you have one, you'll need to load up the Particle App. You can either get that from the Athom App Store (assuming I've successfully published it there - TODO) or you can load it manually using the Athom node.js CLI and grabbing it from github [athom-particledevice](https://github.com/specialcircumstances/athom-particledevice) 

Once the Particle App is setup (see the instructions at [athom-particledevice](https://github.com/specialcircumstances/athom-particledevice) ) you will need to add this library to your Particle project. The library will be published soon to Particle so should be easy to include in your projects.


## Usage


```
#include "athomdevice.h"

Athomdevice myDevice; // Create ONE device.

int myDimLevel = 0;
bool myOnOff = false;

// Your function to return a value on a Get from Homey, can be int, float or bool.
bool getOnOffCallback() {
  return myOnOff;
}

int getDimLevel() {
  return myDimLevel;  // You might actually read a sensor or that could be done elsewhere and the result stored
}

// Your function to adjust something, e.g. a dim level on a light. 
// Can be int, float or bool. Must accept one value, and return the actual set value
// The parameter and return type MUST be the same.
// This is a Homey "Set"

bool setOnOffCallack(const bool myNewVal) {
  myOnOff = myNewVal; // or actually do something
  return myOnOff;
}

int setDimCallback(const int myNewVal) {
  myDimLevel = myNewVal;  // or actually do something
  return myOnOff;
}


// In setup you need to declare the number of "nodes", a class for each node, 
// and what Homey capabilities each node supports.
// Then attach the callbacks
void setup() {
  myDevice.setName("TESTY"); // A name, optional
  myDevice.addNode("light"); // (sub) Nodes are added sequentially, at setup time, specify the class.
  myDevice.addCapability(1,"onoff");  // Add the "onoff" capability to node 1
  myDevice.setCapabilityGetCallback(1,"onoff",&getOnOffCallback);   // Pointer to your function to return the value
  myDevice.setCapabilitySetCallback(1,"onoff",&setOnOffCallback);   // Pointer to your function to set the value
  myDevice.addCapability(1,"dim");
  myDevice.setCapabilityGetCallback(1,"dim",&getDimCallback);
  myDevice.setCapabilitySetCallback(1,"dim",&setDimCallback);
}

// You can either get Homey to poll your device, or you can manually send reports. You can do both if you like
void loop() {
  myDevice.sendReport();  // This will trigger a report of all getable capabilities.
  delay(60000);           // wait 60 seconds until the next one.
}
```


## Classes and Capabilties

You must use known Homey classes and capabilities. See the [Driver Reference](https://developer.athom.com/docs/apps/tutorial-Drivers-Reference.html)



## BELOW HERE BOILERPLATE

## Welcome to your library!

To get started, modify the sources in [src](src). Rename the example folder inside [examples](examples) to a more meaningful name and add additional examples in separate folders.

To compile your example you can use `particle compile examples/usage` command in [Particle CLI](https://docs.particle.io/guide/tools-and-features/cli#update-your-device-remotely) or use our [Desktop IDE](https://docs.particle.io/guide/tools-and-features/dev/#compiling-code).

Libraries can also depend on other libraries. To add a dependency use [`particle library add`](https://docs.particle.io/guide/tools-and-features/cli#adding-a-library) or [library management](https://docs.particle.io/guide/tools-and-features/dev/#managing-libraries) in Desktop IDE.

After the library is done you can upload it with `particle library upload` or `Upload` command in the IDE. This will create a private (only visible by you) library that you can use in other projects. If you wish to make your library public, use `particle library publish` or `Publish` command.

_TODO: update this README_

## Usage

Connect XYZ hardware, add the athomdevice library to your project and follow this simple example:

```
#include "athomdevice.h"
Athomdevice athomdevice;

void setup() {
  athomdevice.begin();
}

void loop() {
  athomdevice.process();
}
```

See the [examples](examples) folder for more details.

## Documentation

TODO: Describe `Athomdevice`

## Contributing

Here's how you can make changes to this library and eventually contribute those changes back.

To get started, [clone the library from GitHub to your local machine](https://help.github.com/articles/cloning-a-repository/).

Change the name of the library in `library.properties` to something different. You can add your name at then end.

Modify the sources in <src> and <examples> with the new behavior.

To compile an example, use `particle compile examples/usage` command in [Particle CLI](https://docs.particle.io/guide/tools-and-features/cli#update-your-device-remotely) or use our [Desktop IDE](https://docs.particle.io/guide/tools-and-features/dev/#compiling-code).

After your changes are done you can upload them with `particle library upload` or `Upload` command in the IDE. This will create a private (only visible by you) library that you can use in other projects. Do `particle library add athomdevice_myname` to add the library to a project on your machine or add the athomdevice_myname library to a project on the Web IDE or Desktop IDE.

At this point, you can create a [GitHub pull request](https://help.github.com/articles/about-pull-requests/) with your changes to the original library.

If you wish to make your library public, use `particle library publish` or `Publish` command.

## LICENSE
Copyright 2018 SpecialCircumstances

Licensed under the GNU GPLv3 license
