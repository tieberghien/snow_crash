#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>
 
int main(int argc, char **argv, char **envp)
{
    gid_t gid;
    uid_t uid;
	char *buf;
    gid = getegid();
    uid = geteuid();
 
	setresgid(gid, gid, gid);
	setresuid(uid, uid, uid);
    asprintf(&buf, "/bin/echo %s", getenv("LOGNAME"));
	system(buf);
}
