# Tutorial on including external library in ceedling
 Create a ceedling project.
 * Details on creating ceedling project can be found [here](https://github.com/chaosAD/HowToCreateCeedlingProject)

Download and extract any libraries that you wish to include. (we use json-c for examples). [link to json-c](https://github.com/json-c/json-c)
## building the library

change directory into json-c and build it by typing :
```
$ cd json-c
$ sh autogen.sh
```
type **./configure** for getting ready to build the software on your specific system. The default location of library installed is *usr/local*
```
$ ./configure
```
Similarly, if you want to installed in a different directory
```
$ ./configure --prefix=path/to/your/folder
```
To build the sofware:
```
$ make
```
To install the software in the directory that you configure, or to the default *usr/local*
```
$ make install
```

## linking the library
open up your project.yml file and add following:
```
:test_linker:
  :executable: gcc                  #absolute file path
  :name: 'gcc linker'
  :arguments:
    - ${1}                          #list of object files to link (Ruby method call param list sub)
    - -o ${2}                       #executable file output (Ruby method call param list sub)
```
To specify the location for searching the external library, use **-L**option flag to specify the location.
```
:test_linker:
  :executable: gcc                  #absolute file path
  :name: 'gcc linker'
  :arguments:
    - ${1}                          #list of object files to link (Ruby method call param list sub)
    - -o ${2}                       #executable file output (Ruby method call param list sub)
    - -L<path/to/your/folder>       #add a location for searching library
```
To include the json-c library
```
:test_linker:
  :executable: gcc                  #absolute file path
  :name: 'gcc linker'
  :arguments:
    - ${1}                          #list of object files to link (Ruby method call param list sub)
    - -o ${2}                       #executable file output (Ruby method call param list sub)
    - -L<path/to/your/folder>       #add a location for searching library
    - -ljson-c                      #link with json-c library NOTE: should not include the prefix *lib*
```
