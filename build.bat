@echo off

devenv Graphics.sln /build debug
pushd bin
pushd Debug
if exist "Graphics project.exe" "Graphics Ppoject.exe"
popd
popd