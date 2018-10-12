# OCTA test application
- Setup:
    - Connect a usb cable to the FTDI connector of the octa board
    - Set up a serial connection with baudrate 115200 to read UART logs
- Firmware:
    - `(sudo) make all flash term`
    - accelerometer data from LSM sensor should appear in the serial monitor
    - RGB led will blin R->G->B