# boneleds
Random control PWM leds on beaglebone
Using board http://elinux.org/Boneleds

Installed ubuntu on emmc.
Needed changes:
1. uEnv.txt - included in repository

2. Compile ledControl.c

3. sudo crontab -e
Add a line @reboot /home/ubuntu/ledControl&
