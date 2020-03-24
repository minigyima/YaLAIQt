# YaLAIQt

YaLAI - The Qt rewrite

YaLAI is graphical installer built for Arch Linux, with an aim to create a customizable, vanilla Arch install, with little effort.
Keep in mind, that this is the source code for the installer. The iso can be found at *https://github.com/minigyima/yalai-iso

## Features
- A graphical UI written in Qt5
- Full preseed support, so if you don't fancy going through the installer every time, you can just load a script.
- Customizable list of installed apps
- Full AUR support (yay), with a customizable list of apps

## Build instructions

### Prerequisites

A Linux machine, with a Qt5 development environment (Qt5 + qmake)

### Building the project

Just execute the following code in a terminal (In the project directory)

```
qmake && make
```
## Releases

If you don't fancy building the project yourself, you can find the latest executable, with the scripts in the 'Releases' tab.

## Built With

* Qt5 [https://www.qt.io]

## Authors

* **Máté Gyimesi** - *Initial work* - [minigyima](https://github.com/minigyima)

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments
* Massive thanks to Jody James and Josiah Ward, as some code was adopted from the Zen installer.
