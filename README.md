# English RPi Project
Project unfinished, it's highly experimental and work mainly on wifi cards > 2013.

## Thanks
Thanks to [bmegli](https://github.com/bmegli) for the [wifi-scan](https://github.com/bmegli/wifi-scan) Library.

## To build
You only need to do a `make B=ss` to build it, the release will be in the bin folder.

- **Dependencies**
- [Arch](#Archlinux)
- [Debian / Ubuntu](#Debian_or_Ubuntu)

### Archlinux
- linuxXXX-headers *(replace XXX with your linux kernel version)*
- libmnl

### Debian or Ubuntu
- build-essential
- libmnl0 libmnl-dev
- linux-headers-XXX *(replace XXX with the result of `uname -r`)*
