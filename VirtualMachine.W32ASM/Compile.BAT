@echo off

cd src
\ASM\tasm32 /ml /m /zn /w0 /dTASM /n /i pmScript, pmScript, ..\pmScript
\ASM\tlink32 /Tpd /V4.0  /aa /c /m /ml /x pmScript,,,,pmScript.def
\ASM\Implib -c pmScript.lib pmScript.dll

copy /Y pmScript.lib ..\release\pmScript.lib
copy /Y pmScript.dll ..\release\pmScript.dll

del pmScript.lib
del pmScript.dll
del pmScript.obj

cd ..\release

\tools\vgalign pmScript.dll

pause
