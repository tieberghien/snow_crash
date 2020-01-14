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
    (gdb) set $eax=3014
    (gdb) finish
    Run till exit from #0  0xb7ee4cc0 in getuid ()
       from /lib/i386-linux-gnu/libc.so.6
    0x08048b02 in main ()
    (gdb) jump *0x8048de5
    Continuing at 0x8048de5.
    Check flag.Here is your token : 7QiHafiNa3HVozsaXkawuYrTstxbpABHD8CPnHJ
    [Inferior 1 (process 2926) exited normally]
```
