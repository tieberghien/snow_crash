### Exploit

In order to complete level00, you have to watch the Elearning video first. Otherwise, you won't know how to approach this level. Supposedly, these are the first steps you need to follow:
```
    level00@SnowCrash:~$ ls
    README
    level00@SnowCrash:~$ cat README
    FIND this first file who can rule only as flag00...
```

Let's just do that then.
```
    level00@SnowCrash:~$ find / -user flag00
    README
    level00@SnowCrash:~$ cat README
    FIND this first file who can rule only as flag00...
```

1. [HTML/XML escape](https://www.w3.org/International/questions/qa-escapes#use) all user inputs so they can't be interpreted by the browser as HTML.
