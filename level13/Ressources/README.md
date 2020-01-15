### Exploit

Once again, let's play with the binary a little bit. 

```
    level13@SnowCrash:~$ ./level13
    UID 2013 started us but we we expect 4242
    level13@SnowCrash:~$ id
    uid=2013(level13) gid=2013(level13) groups=2013(level13),100(users)
```
We can't run the script properly as `level13`. Obviously, we can't simply change our UID to __4242__, because this would require root privilege. We've got to modify the value of "UID" directly within the script. First off, let's launch GDB. 

```
    level13@SnowCrash:~$ gdb -q level13
    Reading symbols from /home/user/level13/level13...(no debugging symbols found)...done.
    (gdb) set disassembly-flavor intel
    (gdb)
    (gdb) break main
    Breakpoint 1 at 0x804858f
    (gdb) r
    Starting program: /home/user/level13/level13

    Breakpoint 1, 0x0804858f in main ()
    (gdb) disas main
    Dump of assembler code for function main:
       0x0804858c <+0>:	    push   ebp
       0x0804858d <+1>:	    mov    ebp,esp
    => 0x0804858f <+3>:	    and    esp,0xfffffff0
       0x08048592 <+6>:	    sub    esp,0x10
       0x08048595 <+9>:	    call   0x8048380 <getuid@plt>
       0x0804859a <+14>:	cmp    eax,0x1092
       0x0804859f <+19>:	je     0x80485cb <main+63>
       0x080485a1 <+21>:	call   0x8048380 <getuid@plt>
       0x080485a6 <+26>:	mov    edx,0x80486c8
       0x080485ab <+31>:	mov    DWORD PTR [esp+0x8],0x1092
       0x080485b3 <+39>:	mov    DWORD PTR [esp+0x4],eax
       0x080485b7 <+43>:	mov    DWORD PTR [esp],edx
       0x080485ba <+46>:	call   0x8048360 <printf@plt>
       0x080485bf <+51>:	mov    DWORD PTR [esp],0x1
       0x080485c6 <+58>:	call   0x80483a0 <exit@plt>
       0x080485cb <+63>:	mov    DWORD PTR [esp],0x80486ef
       0x080485d2 <+70>:	call   0x8048474 <ft_des>
       0x080485d7 <+75>:	mov    edx,0x8048709
       0x080485dc <+80>:	mov    DWORD PTR [esp+0x4],eax
       0x080485e0 <+84>:	mov    DWORD PTR [esp],edx
       0x080485e3 <+87>:	call   0x8048360 <printf@plt>
       0x080485e8 <+92>:	leave
       0x080485e9 <+93>:	ret
    End of assembler dump.
```
As we disassemble the programme. we notice at __0x0804859a__ the value of register $eax is compared to 0x1092, that is, 4242. $eax is set to 2013, because it received the return value of the function `getuid`. Moving on to __0x0804859f__, if $eax isn't equal to 4242, the programme continues, prints out an error message at __0x080485ba__ and exit. On the other hand, if $eax is indeed equal to 4242, the programme jumps to <main+63>, hashes the level's token, prints it, and then exits. All we have to do now is set the value of register $eax to 4242.

```
    (gdb) b *0x0804859a
    Breakpoint 2 at 0x804859a
    (gdb) c
    Continuing.

    Breakpoint 2, 0x0804859a in main ()
    (gdb) p $eax
    $1 = 2013
    (gdb) set $eax = 4242
    (gdb) p $eax
    $2 = 4242
    (gdb) c
    Continuing.
    your token is 2A31L79asukciNyi8uppkEuSx
    [Inferior 1 (process 30790) exited with code 050]
```
This is the last stretch!
