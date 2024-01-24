# Mastermind-Revamp

A single player spin on the the 2-playerboard game Mastermind with a surprise musical ending. Is implemented using arduino hardware and software, designed to be physically interactived with by the user.

## Description

An in-depth paragraph about your project and overview of use.

## Getting Started

### Dependencies

*Windows 10
*Arduino Version 1.8.16

### Installing

* Main file can be found under ```MastermindMain.ino``` as well as the files for sound (for the buzzer) under ```RickSoundFiles.h``` and for timing of the files, used in place of the ```delay()``` function to allow for different functionability simultaneously across the system, found under ```Timer.h```.
* Any modifications needed to be made to files/folders

### Executing program

* After making sure all your hardware is correctly wired up to the bedboard and Arduino (if you have issues getting the code to work as intended, chances are the issue(s) lie here) click the upload button to the upper left of the Arduino software interface (or hit ```Ctrl U```)
* If you recieve the error code ```An error occurred while uploading the sketch
avrdude: ser_open(): can't open device "\\.\COM9": The system cannot find the file specified``` you either have not plugged in the USB 2.0 Cable Type A/B to your board and computer, or (more likely) you have not set output to the correct port. Check under Tools in th eupper left to fix this. 
* Step-by-step bullets
```
code blocks for commands
```

## Help

Any advise for common problems or issues.
```
command to run if program contains helper info
```

## Authors

Contributors names and contact info

ex. Dominique Pizzie  
ex. [@DomPizzie](https://twitter.com/dompizzie)

## Version History

* 0.2
    * Various bug fixes and optimizations
    * See [commit change]() or See [release history]()
* 0.1
    * Initial Release

## License

This project is licensed under the [NAME HERE] License - see the LICENSE.md file for details

## Acknowledgments

Inspiration, code snippets, etc.
* [awesome-readme](https://github.com/matiassingers/awesome-readme)
* [PurpleBooth](https://gist.github.com/PurpleBooth/109311bb0361f32d87a2)
* [dbader](https://github.com/dbader/readme-template)
* [zenorocha](https://gist.github.com/zenorocha/4526327)
* [fvcproductions](https://gist.github.com/fvcproductions/1bfc2d4aecb01a834b46)
