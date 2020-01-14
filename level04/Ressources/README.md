### Exploit

Some Perl scripting going on in this stage... First, go to your localhost:4747, as indicated by the script. Perl's CGI has one major vunerability: calling [param()](https://metacpan.org/pod/distribution/CGI/lib/CGI.pod#Fetching-the-value-or-values-of-a-single-named-parameter) as it is possible to inject other param keys and values into your code if you don't sanitize user input. This is exactly what's going on with this script, as no input is filtered or denied whatsoever. It is therefore possible to inject the command `getflag` into paramater "x".

> http://[YOUR_IP_ADRESS]:4747/?x=`getflag`

> Check flag.Here is your token : ne2searoevaevoem4ov4ar8ap

Perl isn't so bad, is it?
