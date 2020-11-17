# Simple_shell (hsh)

Simple_shell (hsh) is a UNIX command line interpreter that deciphers and executes commands given via standard input, or a file.

## Initializing

Compile with all .c files in the repository, using the wildcard command: *.c. Then, run the executable.

```bash
gcc *.c -o hsh
./hsh
```
Simple_shell can be ran in both interactive, and non-interactive modes.



Interactive mode example:
```bash
$./hsh
$
```
Non-interactive mode example:
```bash
$echo "echo hello world" | ./hsh
$hello world
```



## Builtin Commands


## Authors
Alexander Sweet
Breanna Rickner
Software engineering students at Holberton School.
## Acknowledgements
Partner project from the curriculum at Holberton School.
