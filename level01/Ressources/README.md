### Exploit

Once again, there isn't much to look at to start with. We know we need to find the password to `flag01`. [/etc/passwd](http://www.linfo.org/etc_passwd.html) contains one interesting line:
>   flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash

This is intriguing, to say the least. But `42hDRfypTqqnw` won't let you log in to `flag01`. Time to introduce [John the Ripper](https://www.openwall.com/john/doc/EXAMPLES.shtml). This bad boy will help you "unshadow" traditional Unix password file without root privilege. Use john on a file containing the encrypted password: `abcdefg`, easy as one-two-three.
```
    level01@SnowCrash:~$ su flag01
    Password:
    Don't forget to launch getflag !
    flag01@SnowCrash:~$ getflag
    Check flag.Here is your token : f2av5il02puano7naaf6adaaf
```
Level02, here we come!
