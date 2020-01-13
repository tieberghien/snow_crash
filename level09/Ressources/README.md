### Exploit

Once again, we're provided with two files: one executable file and a text file with a flag. We've got reading rights on `token`.

```
    level09@SnowCrash:~$ ls -l
    total 12
    -rwsr-sr-x 1 flag09 level09 7640 Mar  5  2016 level09
    ----r--r-- 1 flag09 level09   26 Mar  5  2016 token
    level09@SnowCrash:~$ cat token
    f4kmm6p|=�p�n��DB�Du{��
    level09@SnowCrash:~$ ./level09
    You need to provied only one arg.
    level09@SnowCrash:~$ ./level09 $(cat token)
    f5mpq;v�E��{�{��TS�W�����
```
This is not the flag we're looking for. But first, we need to understand how the script works.

```
    level09@SnowCrash:~$ ./level09 AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
    ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abc
```
The rule is: print an ascii character according to its position in a given string parameter, i.e. A + str[0] = A, A + str[1] = B, A + str[2] = C ...etc. My thought at first was to recursively call the script. Perhaps after a number of iteration, we'd get the "real" token. To no avail... The actual solution is to create a script which does exactly the opposite of script `level09`. That is, substract the character position to the ascii character itself. A simple python script will do the trick.

```
  level09@SnowCrash:~$ python /tmp/decrypt.py $(cat token)
  Result: f3iji1ju5yuevaus41q1afiuq
  level09@SnowCrash:~$ su flag09
  Password:
  Don't forget to launch getflag !
  flag09@SnowCrash:~$ getflag
  Check flag.Here is your token : s5cAJpM8ev6XHw998pRWG728z
```
 Congratulations! Now onto the bonus stages.
