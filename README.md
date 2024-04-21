# Polyrhythm
## Project Description
This project is a very simple polyrythm. There are 7 half circles each with a point on it, the point moves along the circle and when it hits the line
that's drawn at the bottom of the half circles, it plays the corresponding note (the biggest plays a Do, the second biggest a Re, etc...).

## Setup
### Dependencies
On a Debian system you can install the needed dependencies using:
```shell
sudo apt install g++ cmake make libsdl2-dev libsdl2-mixer-dev -y
```

### Clone Repository
```shell
git clone https://github.com/llikian/Polyrhythm.git
cd Polyrhythm
```

### Build
To build you can simply run the `build.sh` script at the root of the project using:
```shell
bash build.sh
```

You can also manually build it using:
```shell
cmake -B build && \
cmake --build build -j
```

Then you can run it using:
```shell
bin/Polyrhythm
```

## Credits
The rendering is done using [SDL2](https://www.libsdl.org/).