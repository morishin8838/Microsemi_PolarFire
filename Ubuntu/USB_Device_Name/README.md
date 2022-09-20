# 接続USBデバイス(FlashPro)の名前とデバイス ファイル パスを取得する

## 手順
1. デバイス読み出しスクリプトを作成する。check_usb.sh

```
#!/bin/bash

for sysdevpath in $(find /sys/bus/usb/devices/usb*/ -name dev); do
    (
        syspath="${sysdevpath%/dev}"
        devname="$(udevadm info -q name -p $syspath)"
        
        [[ "$devname" == "bus/"* ]] || [[ "$devname" == "input/"* ]] || [[ "$devname" == "video0"* ]] || exit
        
        eval "$(udevadm info -q property --export -p $syspath)"
        [[ -z "$ID_SERIAL" ]] && exit
        
        busnum="$(udevadm info -a -p  $(udevadm info -q path -n /dev/$devname) | awk -F "==" '/busnum/ {gsub("\"","");print $2}' | head -1)"
        devnum="$(udevadm info -a -p  $(udevadm info -q path -n /dev/$devname) | awk -F "==" '/devnum/ {gsub("\"","");print $2}' | head -1)"
        bus_dev=${busnum}:${devnum}
        lsusb="$(lsusb -s $bus_dev)"
        
        echo "$lsusb - /dev/$devname"
    )
done
```

2. 実行する
```
$bash check_usb.sh
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub - /dev/bus/usb/001/001
Bus 001 Device 003: ID 8087:0a2b Intel Corp.  - /dev/bus/usb/001/003
Bus 001 Device 005: ID 03f0:1198 HP, Inc HID-compliant mouse - /dev/bus/usb/001/005
Bus 001 Device 005: ID 03f0:1198 HP, Inc HID-compliant mouse - /dev/input/event7
Bus 001 Device 005: ID 03f0:1198 HP, Inc HID-compliant mouse - /dev/input/mouse1
Bus 001 Device 002: ID 05e3:0608 Genesys Logic, Inc. Hub - /dev/bus/usb/001/002
Bus 001 Device 004: ID 0b39:0001 Omnidirectional Control Technology, Inc. Composite USB PS2 Converter - /dev/bus/usb/001/004
Bus 001 Device 004: ID 0b39:0001 Omnidirectional Control Technology, Inc. Composite USB PS2 Converter - /dev/input/event3
Bus 001 Device 004: ID 0b39:0001 Omnidirectional Control Technology, Inc. Composite USB PS2 Converter - /dev/input/event5
Bus 001 Device 004: ID 0b39:0001 Omnidirectional Control Technology, Inc. Composite USB PS2 Converter - /dev/input/event6
Bus 001 Device 004: ID 0b39:0001 Omnidirectional Control Technology, Inc. Composite USB PS2 Converter - /dev/input/mouse0
Bus 001 Device 004: ID 0b39:0001 Omnidirectional Control Technology, Inc. Composite USB PS2 Converter - /dev/input/event4
Bus 001 Device 009: ID 2109:2813 VIA Labs, Inc. USB2.0 Hub - /dev/bus/usb/001/009
Bus 001 Device 010: ID 1514:2008 Actel USB2.0 Hub - /dev/bus/usb/001/010
Bus 001 Device 011: ID 1514:2008 Actel  - /dev/bus/usb/001/011
Bus 002 Device 001: ID 1d6b:0003 Linux Foundation 3.0 root hub - /dev/bus/usb/002/001
Bus 002 Device 003: ID 2109:0813 VIA Labs, Inc. USB3.0 Hub - /dev/bus/usb/002/003
```

3. デバイスの実行権限を変更する

```
$cd /dev/bus/usb/001
$ sudo chmod +x 010
$ sudo chmod +x 011
```

