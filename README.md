# Mastermind-Revamp

A single player spin on the the 2-playerboard game Mastermind with a surprise musical ending. Is implemented using arduino hardware and software, designed to be physically interactived with by the user.

## Description

Using the Arduino Uno as well as some jumper wires and additional components, I have created a hardware based minigame based off of a board game I played growing up. The gist of the game is that it is a guessing game, where each guess wins you some type of hit(s) to try and push you closer to a 4-color combo key. For this version of the game, I did not design it like that, however it does more or less follow the same idea, just with an infinite number of guesses and numbers instead of colors. Using an analog joystick, the user can change the x-values (shifting left or right) to switch between any of the 4-digit place holders on a 4-digit 7-segment display. To actually change the values, they can change the y-values (up or down). Upon reaching the highest number 9, pressing up will wrap back around to 0, and trying to go below zero will jump you to 9, etc..

To submit your guess, you press the joystick button (pressing the joystick inward does this). You could also wire it to be an actual external button, but current implementation is via the joy. At this point, 4 pitches will ring out from the passive buzzer. High pitch indecates correct digit in correct place, where a low pitch means that is not the correct number. 

EX: If the answer code is 1-2-3-4 and user's input is 1-2-5-6, user will hear a high-high-low-low series of pitches. 

Every time you input the full correct combination, a victory song will play from the buzzer. There is currently only one song. However, after every round where the correct code is inputted, the code will change and you have the oppurtunity to guess over and over again.

A link to a video of all of this being performed is a available [here](https://www.youtube.com/watch?v=ptimEnspqRY)

## Getting Started

### Dependencies

* Windows 10
* Arduino Version 1.8.16

### Installing

* Main file can be found under ```MastermindMain.ino``` as well as the files for sound (for the buzzer) under ```RickSoundFiles.h``` and for timing of the files, used in place of the ```delay()``` function to allow for different functionability simultaneously across the system, found under ```Timer.h```.
* Upload these files to Arduino - this project was created/runs successfully on Arduino 1.8.16, however any later versions of Arduino *should* also work just fine

### Executing program

* After making sure all your hardware is correctly wired up to the bedboard and Arduino (if you have issues getting the code to work as intended, chances are the issue(s) lie here) click the upload button to the upper left of the Arduino software interface (or hit ```Ctrl U```)
* If you recieve the error code ```An error occurred while uploading the sketch
avrdude: ser_open(): can't open device "\\.\COM9": The system cannot find the file specified``` you either have not plugged in the USB 2.0 Cable Type A/B to your board and computer, or (more likely) you have not set output to the correct port. Check under Tools in th eupper left to fix this. 
* Step-by-step bullets
```
code blocks for commands
```

## Authors

Alexis Stephens  

## Version History

* 0.2
    * Updated README file to include instructs/functional video
    * See [commit change]() or See [release history]()
* 0.1
    * Initial Release
