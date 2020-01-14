### Exploit

Once more, we're welcomed with an empty repository... You might as well look for a binary to exploit, a hidden file to decrypt, and so on, and so forth, until the end of the night. Luckily, there actually IS a binary to crack. Indeed, we know `getflag` is specific to __snow-crash__. If our intuition's right, we could've captured every flag of every level just by tampering with `getflag`. Besides, whenever we tried to have a go at it, we're being told "You should not reverse this" (sic). You leave me no choice, mate.

A quick look around the binary lets us know that, in order to retrieve the correct token and move on to the next stage, the programme first check the value of register $eax. Unsurprisingly, the uid for flag14 is 3014 (0bc6). But before we tamper with the function `getuid`, we need to get around the call to `ptrace`. As it fails, it very logically returns -1, which prevents us from digging deeper into the code. Here are the first couple of steps we need to take. 

```
    level14@SnowCrash:~$ gdb -q /bin/getflag
    Reading symbols from /bin/getflag...(no debugging symbols found)...done.
    (gdb) set disassembly-flavor intel
    (gdb) b main
    Breakpoint 1 at 0x804894a
    (gdb) b getuid
    Breakpoint 2 at 0x80484b0
    (gdb) b *0x0804898e
    Breakpoint 3 at 0x804898e
    (gdb) r
    Starting program: /bin/getflag

    Breakpoint 1, 0x0804894a in main ()
    (gdb) c
    Continuing.

    Breakpoint 3, 0x0804898e in main ()
    (gdb) set $eax=0
    (gdb) c
    Continuing.

    Breakpoint 2, 0xb7ee4cc0 in getuid () from /lib/i386-linux-gnu/libc.so.6
 ```
By setting $eax at 0, we prevent the programme from exiting before we reach breakpoint __0x80484b0__. Once we get to the `getuid `address, we know simply set $eax to a new value, 3014 and "finish". This [command line](https://www.roe.ac.uk/~ert/stacpolly/idb_manual/common/idb_the_return_command.htm)'s purpose is to continue execution of the current function until it returns to its caller. We are now free to access any address we please, from within the function.
 
 ```
    (gdb) set $eax=3014
    (gdb) finish
    Run till exit from #0  0xb7ee4cc0 in getuid ()
       from /lib/i386-linux-gnu/libc.so.6
    0x08048b02 in main ()
    (gdb) jump *0x8048de5
    Continuing at 0x8048de5.
    Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
    [Inferior 1 (process 2941) exited normally]
    (gdb) quit
    level14@SnowCrash:~$ su flag14
    Password:
    Congratulation. Type getflag to get the key and send it to me the owner of this livecd :)
    flag14@SnowCrash:~$ getflag
    Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
```

Yes, we did it! À MOI L'EXP, MIAM MIAM LE T3.
