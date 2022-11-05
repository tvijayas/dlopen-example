# dlopen-example in Linux

Simple example to see how dlopen() can be used...

Checking the behaviour of the same .so library both dynamically linked & dynamically loaded in a binary.

```
dependecnies
sudo apt-get install build-essentials
sudo apt-get install cmake
```

#clone the project
#cd to git directory

run the below command will create the  libmylib.so & a.out binary
```
./compile 
```
a.out links the libmylib.so both at buildtime & runtime. the counter in libmylib.so is incremented both 
by direct function call & by dlopen call.

output:
```
mylib loaded 
I'm in main
2
handle1 = 2439537088
handle2 = 2439537088
3
4
mylib unload 
```
