@ECHO OFF
IF NOT EXIST build (mkdir build)
cd build
cmake -G "Visual Studio 10" ..
cd ..
pause
exit