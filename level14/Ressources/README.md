(gdb) x/s 0x8048fa8
0x8048fa8:	 "You should not reverse this"
(gdb) b *0x0804898e
Breakpoint 2 at 0x804898e
(gdb) r
Starting program: /bin/getflag

Breakpoint 1, 0x08048946 in main ()
(gdb) c
Continuing.

Breakpoint 2, 0x0804898e in main ()
(gdb) p $eax
$1 = -1
(gdb) i r
eax            0xffffffff	-1
ecx            0xb7e2b900	-1209878272
edx            0xffffffc8	-56
ebx            0xb7fd0ff4	-1208152076
esp            0xbffff5e0	0xbffff5e0
ebp            0xbffff708	0xbffff708
esi            0x0	0
edi            0x0	0
eip            0x804898e	0x804898e <main+72>
eflags         0x200282	[ SF IF ID ]
cs             0x73	115
ss             0x7b	123
ds             0x7b	123
es             0x7b	123
fs             0x0	0
gs             0x33	51
(gdb) x/s 0xbffff5e0
0xbffff5e0:	 ""
(gdb) x/s 0xb7e2b900
0xb7e2b900:	 ""
(gdb)
0xb7e2b901:	 "\271\342\267", <incomplete sequence \342\267>
(gdb) set $eax = 1
(gdb) p $eax
$2 = 1
