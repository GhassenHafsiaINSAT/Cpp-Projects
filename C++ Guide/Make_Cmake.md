# Makefiles

- Makefiles are used to help decide which parts of a large program need to be recompiled.

## Makefile syntax

```sh
targets: prerequisites  
 command 
 command 
 command
```

- prerequisities are also called dependencies, they need to exist before the commands for the target are run.

- The targets are file names. Typically, there is only one per rule.

- Commands are a series of steps typically used to make the target, they need to start with a tab character

## The essence of Make

```sh
hello:
 echo "Hello, World"
 echo "This line will print if the file hello does not exist."
```

- As long as the `hello` files does not exist, the commands will run.  
  
- Since there's no target supplied as an argument to the make command, the first target is run.

## Make clean

- `clean` is often used as a target that removes the output of other targets

```sh
clean:
 rm -f some_file
```

## Variables

- Variables can only be strings, you can use `:=` or `=`.  
- single or double quotes have no meaning to Make.  
- Reference variables using either ${} or $()

```sh
files := file1 file2
some_file: $(files)
```
