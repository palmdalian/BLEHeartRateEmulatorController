HeartEmulator.py
=====================

Originally based off https://github.com/fg1/BLEHeartRateLogger
HeartEmulator.py is a Bluetooth Low-Energy (BLE) Heart Rate Monitor (HRM) written in Python for the Raspberry Pi. The main purpose is to send commands to an Arduino to control the speed of an SNES emulator using simple keyboard commands.

Communication with the BLE HRM is established using `hcitool` and `gatttool`. The output of those tools is then parsed and saved to an sqlite database.



## Installation

On the RPi (as of 7/2015):
Install bluez from source to get the -random option required for some BLE devices.
```
$ apt-get install python-pexpect
$ git clone https://github.com/palmdalian/BLEHeartRateEmulatorController.git
```

Run the script as root or correctly specify the rights on `hcitool` and `gatttool`.



## Usage

To start the tool (as root or with correct rights):
```
# ./HeartEmulator.py
2015-10-23 01:04:05,261  Establishing connection to 11:22:33:44:C6:25
2015-10-23 01:04:35,438  Establishing connection to 11:22:33:44:C6:25
2015-10-23 01:04:36,242  Connected to 11:22:33:44:C6:25
Target heart rate starts at 63

```

To quit the tool, simply Ctrl-C.


Command line options:
```
usage: BLEHeartRateLogger.py [-h] [-m MAC] [-b] [-g PATH] [-o FILE] [-v]

Bluetooth heart rate monitor data logger

optional arguments:
  -h, --help  show this help message and exit
  -m MAC      MAC address of BLE device (default: auto-discovery)
  -b          Check battery level
  -g PATH     gatttool path (default: system available)
  -o FILE     Output filename of the database (default: none)
  -v          Verbose output
```



## Troubleshooting

In case the tool is not able to connect to your BLE HRM, first check manually that your computer and BLE HRM device are able to talk to eachother using the following steps (as root).
```
# hcitool lescan
```
This should list the BLE devices around you with their MAC address with something which looks like this: 00:11:22:33:44:55. You can safely Ctrl-C when the device has been found. We will the connect to the device:
```
# gatttool -b 00:11:22:33:44:55 -I
```
This should open a prompt. Type the following commands:
```
> connect
> characteristics
> exit
```

In case one of the steps mentionned above fails, check your Linux installation and eventually `bluez` version (>= v.5 recommended).



## Contributing

Contributions are welcome.

1. [Fork the repository](https://github.com/palmdalian/BLEHeartRateEmulatorController/fork)
2. Create your feature branch (`git checkout -b my-feature`)
3. Commit your changes (`git commit -am 'Commit message'`)
4. Push to the branch (`git push origin my-feature`)
5. Create a pull request

