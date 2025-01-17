# PA10 - Pinball
<!-- comment format for markdown-->
## Group Members
Ashanti Cudiamat<br/><br/>
Courtney Palmer<br/><br/>
Christine Vaughan

## Project Description
<!-- In Project 9, we added lighting effects to PA8. We added per-vertex lighting and per-fragment lighting, with the shaders swappable with a keystroke. The parameters of the lighting can be adjusted. -->
Building upon project 9, we created an interactive pinball game. The Pinball machine displays various graphical applications such as Modeling objects in blender, mapping textures, applying lighting, and applying physics. 

## Cmake Instructions
The building of the project is done using CMake, installation with apt-get or brew may be necessary. Later use with CMake and Shader files will be require the copy of a directory where those files are stored (ex. shaders). To do this in the ```add_custom_target``` function place 
```cmake
COMMAND ${CMAKE_COMMAND} -E copy_directory ${PROJECT_SOURCE_DIR}/shaders/ ${CMAKE_CURRENT_BINARY_DIR}/shaders
mkdir build
cd build
cmake ..
make
```

## Command Line Instructions
First, make sure that the files were built using standard cmake procedures [described in the CMake Instructions section].

To run the program, navigate to your executable build folder and open a terminal. Then, run
```
./PA10 -v vLight-shader-v.txt fLight-shader-v.txt  -f vLight-shader-f.txt fLight-shader-f.txt
```
NOTES: 
<ul>
<li>The shaders files are provided in the Assets->Shaders folder. You can also use any vertex shader and fragment shader file when running the program. If new shader files are used, they must be added within Assets->Shaders prior to running the program. The -v flag must immediately precede the specefied vertex shaders and the -f flag must immediately preceed the fragment shaders, and the vertex shaders must go before the fragment shaders. There must be an equal number of vertex and fragment shaders, and matching shaders must go in the same order. For example, the first vertex shader after the -v flag is paired with the first fragment shader after the -f flag.</li>
<li>There are several .obj and .mtl files provided within the Assets->Models folder. You may use any .obj and .mtl file as long as it has been placed inside the Assets->Models folder.The name of the desired .obj file must be added in the appropriate place in the config file to be added to the program.</li>
<!--<li>There are several textures provided within the Assets->Textures folder. You may use any image file as long as it has been placed inside the Assets->Textures folder.The name of the desired texture must be added in the appropriate place in the config file to be added to the program.</li>
</ul>-->

## Controls
<!--### Cube
'up'      | Move forward<br/>
'down'    | Move backward<br/>
'left'    | Move left<br/>
'right'   | Move right<br/>
'space'   | Jump-->

### Lighting
'f'      | Use fragment lighting shader<br/>
'v'      | Use vertex lighting shader<br/>
'c'      | Use flat lighting shader<br/>
'y'      | Decrease ambient light <br/>
'u'      | Increase ambient light<br/>
'j'      | Decrease diffuse light <br/>
'h'      | Increase diffuse light<br/>
'm'      | Decrease specular light <br/>
'n'      | Increase specular light<br/>

### Pinball Controls
'p'/'e'  | Right Paddle<br/>
'i'/'q'	 | Left Paddle<br/>
'o'	     | Trigger Plunger - hold o to pull back further<br/>
'r'	     | Reset Game<br/>
't'	     | Top Down Camera view<br/>
'z'	     | Default Camera view<br/>
'x'	     | Follow Ball<br/>

## Extra Credit
Plunger moves back further and intensity of force it exerts on the ball changes based on how long you hold the 'o' key.
The game can be reset by pushing the 'r' button.
Flat shading can be used by pressing 'c'.
