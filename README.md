# SEDS-UCF IREC 2019 Flight Computer

## Overview
This is the software repository for the flight computer aboard SEDS-UCF's IREC 2019 rocket, Tempest. This is the first year we've attempted a flight computer integrated into the airframe rather than just as a component as our payload. This, combined with the switch to a hybrid motor, means that Tempest's flight computer is responsible for a lot more this year than any of our prior launch vehicles.

The flight computer is comprised of an STM32F427 microcontroller, four ICM-20948 IMUs (the successor to the MPU-9250), two BMP388 barometric pressure sensors, a SI4063 RF transmitter, an SD card, and some other electrical shenanigans, all brought together on a student-designed PCB.

The initial codebase was generated using STM32CubeMX, and our interactions with the MCU will utilize the HAL. We intend to write our own libraries for communication with our sensors and transmitter over SPI.

For more information on the project and to follow our progress in other areas of the rocket, visit [our project website.](irec19.sedsucf.org)

## Contributing
This section is written primarily for other SEDS-UCF IREC team members. Because of the nature of the project, unfortunately we can only accept contributions from UCF students who are dues-paying SEDS-UCF members.

If this applies to you, great! You're about to help us get one step closer to launching Tempest! Due to very limited hardware availability, only a few of us will consistently have access to a flight computer and the hardware required to debug it. Thus, if you'd like to just go in blind and code away, have at it! Anything that doesn't compile will eventually be caught and corrected. If you would like to ensure your code compiles, you have two options. To compile an actual binary that could run on the flight computer requires an additional file not in this repo due to restrictions on distribution. Contact Benjamin Straw on the project Slack to receive the file. Alternatively, an easier route is to just comment out lines 17 and 31 of `CMakeLists.txt`.

I've tried to simplify the structure of the codebase as much as possible:
- For our purposes, the main entry point for our program is in the `FlightComputer.c` file. `FC_Setup` will be called after the microcontroller finishes its initialization, and `FC_Tick` will be called after that in an infinite loop with no delay. `FlightComputer.h` contains some important variable declarations and header includes, and almost every other file we write will need to include this header.
- The actual entry point and all the required MCU initialization is handled in the `System` directory. Please don't touch anything in there! There are hooks in `main.c` to `FC_Setup` and `FC_Tick`, which should serve our purposes just fine.
- `Drivers` is the auto-generated Hardware Abstraction Library, which is how we'll be interfacing with the STM32 hardware. Again, best not to mess with this directory if we can at all help it.
- `States` contains the implementations of the six main states of the program: Initialization, Pad Idle, Terminal Count, Ascent, Coast, and Landed. A these should be somewhat light files, mostly calling auxiliary functions in the `Auxiliary` directory.
- Finally, the `Auxiliary` directory contains all the code that isn't a state. Any sensor interfaces, control systems, trajectory simulations... Most of the code we end up writing will end up in this directory or it's subdirectories.

To take a quick look at what the calls look like, the assembly program `startup.stm32f427xx.s` calls the `main()` entry point in `main.c`, which in turn calls `FC_Tick()` in `FlightComputer.c`, which then calls the correct state function for whichever state we're currently in.

A note about the states, they are designed to return _fast_. Avoid any delay functions at all costs, instead utilizing the state timer. We should _never_ hang inside a state.

Other development guidelines will be added here as we stumble upon them. Feel free to ask any questions you may have in the #electronics channel of the Slack.
