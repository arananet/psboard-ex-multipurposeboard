# PS board - Ex The multipurpose board
This project has been renamed to psboard because now this board module it's specially made for the Amiga Super SUPPLY project.

This board is specially designed to display the output voltages of the Meanwell RT65. The project is described here http://blog.arananet.net/fabricando-una-fuente-de-alimentacion-para-amiga/

On the bom directory you will find the bom information and the pick and place information.

On the gerbers directory are the dual layer gerbers required to build this project.

On the Ino directory you will find the ino file that goes inside the atmega. You must upload this using the arduino IDE and the USBASP programmer. You can also upload the code via the TX and RX pins just like when you upload a code on a Arduino Pro Mini. The code is based on this project https://startingelectronics.org/projects/arduino-projects/arduino-4-channel-LCD-voltmeter/

## Oled

This version allows two different types of oleds, 128x32 or 128x64. Both OLEDS pinout must be:

SDA

SCL

VCC

GND

## USB

This new version includes a USB connector so you can also powerup other devices that requires 5V, like charging your mobile phone.

Aliexpress usb connector:

https://es.aliexpress.com/item/32861073445.html?spm=a2g0s.9042311.0.0.274263c0zJIWrg

## Amiga SuperSupply Power button

If your are gonna build my Amiga SupperSupply, and use this board, you will also need this powerswich 

https://es.aliexpress.com/item/32270611983.html?spm=a2g0s.9042311.0.0.274263c0ftBhhi

Here's the case design https://www.thingiverse.com/thing:4753314


# Connection

Required pins for the Amiga SuperSupply are the ones at the most left of the board.

GND > Main GND from PS.

V3 > Volt meter 2 (connect the voltage that you want to monitor)

V2 > Volt meter 1 (connect the voltage that you want to monitor)

V1 > Volt meter 1 (connect the voltage that you want to monitor)

### VIN

You must connect 5V directly from the powersupply to the pin 5VIN on the right side of the board. Also for the USB you must do the same as for the pin 12V, you must connect the pin 12V to the PS too.

# Images

<img src="https://github.com/arananet/multipurposeboard/blob/main/images/3.png?raw=true" width="600">

# Note

### THIS DESIGN OR THE RESULTING PCB IS PROHIBITED TO SALE ON EBAY.

This is a work in progress, several testing must be made but it should work as is. I take no responsibiltiy for any damage to any equipment that results from the use of this board. USE AT YOUR OWN RISK!

If you like the project or want to support it, you can buy me a beer or a KO-FI :) 
[![ko-fi](https://www.ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/H2H51MPWG)
