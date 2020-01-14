#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdio.h>
 
int main(int argc, char **argv, char **envp)
{
    uid_t uid;
    uid = getuid();

    if (uid != 4242)
    {
	printf("UID %d started us but we we expect %d", getuid(), 4242);
	exit();
    }
    printf("your token is %s", ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I"));
}
