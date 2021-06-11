# openssl_sslkeylogfile

1. [Clone and compile openssl](https://github.com/openssl/openssl/blob/master/HACKING.md) in some directory `OPENSSLDEVEL`
1. Specify this directory when running make:
   ```
	 make OPENSSLDEVEL=/usr/local/src/openssl
	 ```
1. Run the target program with `LD_PRELOAD`:
   ```
	 LD_PRELOAD=openssl_keylogfile.so ...
	 ```
