### Exploit

In order to complete `level00`, you have to watch the Elearning video first. Otherwise, you won't know how to approach this level. Supposedly, these are the first steps you need to follow:
```
    level00@SnowCrash:~$ ls
    README
    level00@SnowCrash:~$ cat README
    FIND this first file who can rule only as flag00...
```

(sic) Let's just do that then.
```
    level00@SnowCrash:~$ find / -user flag00
    [...]
    /usr/sbin/john
    [...]
    level00@SnowCrash:~$ cat /usr/sbin/john
    cdiiddwpgswtgt
```

Indeed, this is the file we've been looking for. Yet, `cdiiddwpgswtgt` won't let you log in as `flag00`. A simple letter substitution cipher such as Rot11 will do the trick! The flag is `nottoohardhere`.
```
    level00@SnowCrash:~$ su flag00
    Password:
    Don't forget to launch getflag !
    flag00@SnowCrash:~$ getflag
    Check flag.Here is your token : x24ti5gi3x0ol2eh4esiuxias
```

Now onto the real challenge!
