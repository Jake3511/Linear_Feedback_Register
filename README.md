# LFSR / PhotoMagic

## Contact
Name: Jake Shick

Time to Complete: 5 hours(ps1a) + 1 hour(ps1b) = 6 total hours

## Description
The program takes an image and, using our linear feedback register, encrypts our image into a bunch of different colored pixels that are aquaried through Xoring the integer value of the colors with the 8bit integer we generated from on linear feedback register.  Afterwards, we set the values to a new color and set the pixel held at the x and y position to the new color.

### Features
I used a nested for loop to iterate throughout every single pixel in the image and had i = 0 and go to the end of the x horizontal position and did the same for the y position but only for the vertical.  I then decided to implement a while loop that opened both windows at the same time rather then have one window at a time.  This way you can see the images side by side.

### Issues
Have none that I've noticed.

### Tests
My BOOST functions are very simple, I wanted to test my functions not on what they did right, but what they could detect if something was wrong.  First test was to make sure that my program also worked along with ascii table values.  The second and third test make sure that if my program is given incorrect values or strings, then it will not run correctly or at all.  The last one was just used to make sure my XOR function worked as attended.  I didn't really know what test functions to add to this program since it uses so much of the orginal to do most of work.

## Acknowledgements
https://en.sfml-dev.org/forums/index.php?topic=24954.0

https://www.sfml-dev.org/documentation/2.6.0/classsf_1_1Image.php





