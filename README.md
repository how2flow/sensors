# sensors

### info
- A project to try different sensors on the SBC.
- [Go to Wiki](https://wiki.odroid.com/common/application_note/arduino_sensor_kit/start)

### requirements
- target board: odroid-c4, odroid-n2l
- kernel: 4.9.y
- [odroid-wiringpi](https://github.com/hardkernel/wiringPi) (>= 3.14.5)
```
$ sudo apt install software-properties-common
$ sudo add-apt-repository ppa:hardkernel/ppa
$ sudo apt update
$ sudo apt install odroid-wiringpi libwiringpi-dev
$ git clone https://github.com/how2flow/sensors
```

### examples

* * *

- adc (Photo resistor / KY-018)

![fritzing-analog-input](/examples/kit/fritzing/images/ky-018.jpg)
![analog-input](/examples/kit/gif/ky-018.gif)
```
$ cd sensors/kit/src/analog
$ gcc -o analog-input analog-input.c $(pkg-config --cflags --libs libwiringpi2)
$ ./analog-input
```

* * *

- gpio (Tilt switch / KY-017)

![fritzing-gpio-input](/examples/kit/fritzing/images/ky-017.jpg)
![gpio-input](/examples/kit/gif/ky-017.gif)
```
$ cd sensors/kit/src/gpio
$ gcc -o gpio-input gpio-input.c $(pkg-config --cflags --libs libwiringpi2)
$ ./gpio-input
```

* * *

- pwm (RGB led / KY-016)

![fritzing-pwm-3ch](examples/kit/fritzing/images/ky-016.jpg)
![pwm-3ch](/examples/kit/gif/ky-016.gif)
```
$ cd sensors/kit/src/pwm
$ gcc -o pwm-3ch pwm-3ch.c $(pkg-config --cflags --libs libwiringpi2)
$ ./pwm-3ch
```

* * *

- gpio & pwm (Rotary encoder / KY-040)

![fritzing-gpio-encoder](/examples/kit/fritzing/images/ky-040.jpg)
![gpio-encoder](/examples/kit/gif/ky-040.gif)
```
$ cd sensors/kit/src/gpio
$ gcc -o gpio-encoder gpio-encoder.c $(pkg-config --cflags --libs libwiringpi2)
$ ./gpio-encoder
```

* * *

### contact
<a href="mailto:steve@how2flow.net" target="_blank"><img src="https://img.shields.io/badge/gmail-ea4335?style=flat-square&logo=Gmail&logoColor=white"/></a>
<a href="https://www.youtube.com/channel/UCSixYoVCS1dKRO-FqlBXAiQ" target="_blank"><img src="https://img.shields.io/badge/YouTube-ff0000?style=flat-square&logo=YouTube&logoColor=white"/></a>
