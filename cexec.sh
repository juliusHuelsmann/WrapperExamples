# This file is a shortcut for building and executing the sense project.

# Clean target
if [ "$1" = "clean" ]; then 
  echo "clean!"
  rm -rf build
  rm -rf test/*googletest*
fi


# Check if ninja is available.
which ninja &> /dev/null
useMake=$?
cmakeFlags=""


set -e 

mkdir -p build 
cd build

if [ $useMake -eq 0 ];then
  echo "I use ninja: $useNinja!"
  cmake $cmakeFlags -G Ninja ..
  ninja -j5
else 
  echo "I don't use ninja: $useNinja!"
  cmake $cmakeFlags ..
  make -j5
fi




echo -e "\nExecuting basic usage example:"
examples/usage/wrapperUsage

echo -e "\nExecuting smart pointer example:"
examples/smartPointer/wrapperSmartPointer

echo -e "\nExecuting mutex example:"
examples/mutex/wrapperMutex

