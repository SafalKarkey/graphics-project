@echo off

echo "Setting up the project..."
mkdir bin
pushd bin
mkdir vendor
pushd vendor
mkdir premake
pushd premake

if not exist premake5.exe (
    call curl -L "https://github.com/premake/premake-core/releases/download/v5.0.0-beta2/premake-5.0.0-beta2-windows.zip" -o premake.zip
    tar -x -f premake.zip
    del premake.zip
) else (
    echo "Premake alrady exists"
)

popd
popd
popd

bin\vendor\premake\premake5.exe vs2022