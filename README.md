# Project for Ludum Dare 27

This is a platformer game made for Ludum Dare №27.
Theme was "10 seconds" and game idea is about reaching next checkpoint in that time.
I don't like that theme much but i was excited to make my own platformer and implement jumping from the walls so i finished it in time.

Used technologies:
- OpenGL
- SDL (for dealing with window, input etc and also making possible to port this project to other platforms rather than Windows)
- Box2d for physics
- Tiled for map creation

I didn't use lua this time even though i had my levels written in lua format.
I used standart C++ file reading because of lack of time to setup lua library properly.
Also i recompiled Box2d library to reduce "stickness" of objects.

