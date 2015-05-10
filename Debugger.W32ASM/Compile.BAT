@echo off
echo --------------------------- Compiling Game
cd src
\ASM\RC App.RC
\ASM\tasm32 /kh100000 /m8 /ml /zn /n /w0 App, App, ..\App.lst
\ASM\tlink32 -Tpe -aa -x -c -L..\lib App, ..\App.exe,,,, App.res
del *.obj
del *.res
cd ..

pause