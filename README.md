# RS274 Interpreter cpp libraries

This is part of the `linuxcnc` project, I pick these codes out, and make a library 
which provides cmake configs for `find_package`. This might probably ease the way 
we use this interpreter.

Present I have built this library and the `SAI` which is the stand alone
interpreter. But notice that I *HAVE NOT* exported the `SAI`, just the library
itself. 

I'll do that later.

## NOTICE

- When you use this library, define the `EMC2_DEFAULT_TOOLTABLE` while compiling, 
which should be the path of `sim.tbl` relative to the excutable file.

```bash
# like this in your CMakeLists.txt
add_compile_definitions(EMC2_DEFAULT_TOOLTABLE="tool/sim.tbl")
```

- Later I will give an example how to build the `SAI` out of this project.
And I will tell you what to notice. That's important.