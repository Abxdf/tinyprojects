#!/usr/bin/python
# ./comp.py name extension
''' 
How many times have you written "javac test.java && java test" in order to compile and execute test.java file???
In order to reduce the length of the command that should be typed in order to compile and execute a program...
I have developed this python script. This file takes as command line arguments name and extension of the file 
and executes commands for compiling and executing the program.
For now it supports only c, c++, java, python, scala and racket
'''

import os
from sys import argv
script, name , extension = argv
res = ""
if extension == 'java':
	res = "javac "+ name +".java" + " && " + "java "+name
elif extension == 'py':
	res = "python "+ name + "." + extension
elif extension == 'cpp':
	res = "g++ "+ name +".cpp" + " && " + "./a.out"
elif extension == 'c':
	res = "make "+ name + " && " + "./"+name
elif extension == 'scala':
	res = "scalac "+ name +".java" + " && " + "scala "+name
elif extension == 'rkt':
	res = "racket "+ name + "." + extension

else:
	pass

os.system(res)


