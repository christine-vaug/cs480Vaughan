# PA3: Moons
##Project Description
This program will cause a multi-colored cube to spin around its own center axis and orbit around a center point, while another smaller cube orbits around the first, while spinning on its own axis.
Keyboard and mouse interaction can pause/unpause, reverse, speed up, and slow down the cubes' spin and orbit, and decrease or increase the cubes' sizes. There is an upper and lower limit to the size and speed of the cubes.

## Makefile Instructions 
The makefile works as expected and must be updated with new files added in.

```bash
mkdir build
cd build
cp ../makefile .
make
```

## Command Line Instructions
Use this line in the terminal to run the program:
```bash
./PA3 -v shader-v.txt -f shader-f.txt
```

## Keyboard/Mouse Instructions
### Planet Controls
Reverse orbit - Q<br/>
Pause/Unpause orbit - E or Left Mouse Button<br/>
Reverse spin - Z<br/>
Pause/Unpause spin - C<br/>
Increase size - W<br/>
Decrease size - S<br/>
Increase orbit speed - D<br/>
Decrease orbit speed - A<br/>
Increase spin speed - R<br/>
Decrease spin speed - T

### Moon Controls
Reverse orbit - I<br/>
Pause/Unpause orbit - P or Right Mouse Button<br/>
Reverse spin - N<br/>
Pause/Unpause spin - M<br/>
Increase size - O<br/>
Decrease size - L<br/>
Increase orbit speed - ;<br/>
Decrease orbit speed - K<br/>
Increase spin speed - Y<br/>
Decrease spin speed - U

##Extra Credit
Moon is smaller than planet<br/>
Planet and moon scale with keyboard input<br/>
Planet and moon speed up and slow down orbit and spin with keyboard input