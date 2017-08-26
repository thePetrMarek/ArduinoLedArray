# Arduino LED Array
Code for running 8x8 LED display on Arduino. Information about the project is in blog [Arduino LED array](http://petr-marek.com/blog/2017/08/07/arduino-led-array/). You can also watch the [video demonstrating the project](https://youtu.be/HsX3UoVzPrs).

![Arduino LED Array](http://petr-marek.com/wp-content/uploads/2017/08/Sn%C3%ADmek-obrazovky-70-1024x576.png)

## How to run
Download Arduino IDE. Open file [LEDArray.ino](LEDArray.ino) and upload it to Arduino. I used Arduino Leonardo. You will have mis-matched pin connection to rows and columns of the LED array mot probbably. You can reconfigure the connection in the file [show.ino](show.ino), variables ``row_mapping`` and ``column_mapping``.

## Programs
There are several programs from showing sine function, simple clock, to Game of Life. All programs loops by default and single program runs for two minutes. You can change the setting in [LEDArray.ino](LEDArray.ino) by changing variable ``functions`` and ``programDuration``.
