# PA3: Moons
This program will cause a multi-colored cube to spin around its own center axis and orbit around a center point, while another smaller cube orbits around the first, while spinning on its own axis.
Keyboard and mouse interaction will cause the larger cube's orbit and/or spin to reverse or pause/unpause.

### Makefile Instructions 
The makefile works as expected and must be updated with new files added in.

```bash
mkdir build
cd build
cp ../makefile .
make
./Tutorial
```

### Command Line Instructions
Use this line in the terminal to run the program:
```bash
./PA3 -v shader-v.txt -f shader-f.txt
```
The Shaders are in the Assets folder.

### Keyboard/Mouse Instructions
Reverse orbit - A or Left Mouse Button<br/>
Pause/Unpause orbit - S or Right Mouse Button<br/>
Reverse spin - J<br/>
Pause/Unpause spin - K

