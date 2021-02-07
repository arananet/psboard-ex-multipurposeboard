# The multipurpose board
This is, like his name states, a board that allows use any arduino pro mini or nano project (because is based on a atmega328p) that involves an oled, a microsd and or even a voltmeter.

This board was initially designed for an Amiga Power Supply to display the output voltages of the Meanwell RT65. The project is described here http://blog.arananet.net/fabricando-una-fuente-de-alimentacion-para-amiga/

On the bom directory you will find the bom information and the pick and place information.

On the gerbers directly are the dual layer gerbers required to build this project.

On the Ino directory you will find the ino file that goes inside the atmega. You must upload this using the arduino IDE and the USBASP programmer. You can also upload the code via the TX and RX pins just like when you upload a code on a Arduino Pro Mini.

# Connection

Required pins for the Amiga SuperSupply are the ones at the most left of the board.

GND > Main GND from PS.
Vol2 > Volt meter 2 (connect the voltage that you want to monitor)
Vol1 > Volt meter 1 (connect the voltage that you want to monitor)
5V in > connect to a 5v source to powerup the board.

# Images

<img src="https://github.com/arananet/multipurposeboard/blob/main/images/pcb.png?raw=true" width="600">
<img src="https://github.com/arananet/multipurposeboard/blob/main/images/1.png?raw=true" width="600">
<img src="https://github.com/arananet/multipurposeboard/blob/main/images/2.png?raw=true" width="600">

# Note

### THIS DESIGN OR THE RESULTING PCB IS PROHIBITED TO SALE ON EBAY.

This is a work in progress, several testing must be made but it should work as is. I take no responsibiltiy for any damage to any equipment that results from the use of this board. USE AT YOUR OWN RISK!

If you like the project or want to support it, you can buy me a beer or a KO-FI :) 
[![ko-fi](https://www.ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/H2H51MPWG)
