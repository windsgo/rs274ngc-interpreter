# RS274 Interpreter cpp libraries

This is part of the `linuxcnc` project, I pick these codes out, and make a library 
which provides cmake configs for `find_package`. This might probably ease the way 
we use this interpreter.

Currently I have built this library and the `SAI` which is the stand alone
interpreter, and export them to install. 

## Example

An example to use this library,

See [https://github.com/windsgo/rs274-sai-compile-example](https://github.com/windsgo/rs274-sai-compile-example)

## Build Steps

### Makefile Way (also use cmake in makefile)

Use the Makefile provided. 

1. Modify the `boost_root` and `install_dir` in the Makefile

2. Build it

```bash
make
```

3. install

```bash
make install
```

4. run `sai` test

```bash
./test.sh
```

### CMake Step By Step
1. configure

You need to set **your own variable and prefix** in the following command

```cmake
cmake -B build -DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_INSTALL_PREFIX=${install_dir} \
	-DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
	-DBOOST_ROOT=__YOUR_PREFIX_1__/lib
```
2. build

```cmake
cmake --build build -j8
```

3. install

```
cmake --install build
```

4. run test

```bash
./test.sh
```


## COMPILE NOTICE

- When you use this library, define the `EMC2_DEFAULT_TOOLTABLE` while compiling if your src uses this defination.
which should be the path of `sim.tbl` relative to the excutable file.

```cmake
# like this in your CMakeLists.txt, for example the `sai`
target_compile_definitions(sai
    PRIVATE
    EMC2_DEFAULT_TOOLTABLE="${PROJECT_SOURCE_DIR}/sim.tbl"
)
```

## About RUNTIME Path

I have the following code in CMakeLists.txt:

```cmake
set_target_properties(rs274
    INSTALL_RPATH ${Boost_LIBRARY_DIRS}
)
```

- What does it do?

  Set `INSTALL_RPATH` property to let the INSTALLED library have the search path
  of `libboost_python27.so` at runtime.

- Why I add this?

  When an excutable or another library links to the `INSTALLED TARGET` `rs274` dynamically,
  even though the excutable may link to libboost_python27,
  `librs274.so` **need to know** where to search for `libboost_python27` itself !

- To Mention:

  This should be done, since `libboost_python27` is often not a system lib higher than `Ubuntu20.04`,
  it needs to be set according to different systems.
  So this lib is recommanded to compile each time on a new operating system.

  However, it can also be used if `LD_LIBRARY_PATH` is set proporly 
  or the `libboost_python27` path is included in `/etc/ld.so.conf`.
  
  I do this just to make runtime easier for compile test.