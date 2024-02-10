## Refus
Refus is a simple C program that reads from a given file using the "-f" flag and executes one or multiple commands written inside the program.
It can also read from a single URL using the "-u" flag. Useful for my projects and I decided to make it public because why not!

<br>

- Building the binary executable:
```console
$ gcc refus.c -O2 -o refus
```

- Running refus:
```console
$ ./refus -h
$ ./refus -f filename.txt # For filenames
$ ./refus -u redacted.com # For a single URL
```

<br>
