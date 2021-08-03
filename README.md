# MousePkg
projet efi pour tester la souris
pour construire le projet:


cd <installation d'edk2>

. edksetup.sh

git clone https://github.com/bloginfotech/MousePkg.git


build -a X64 -t GCC5 -p MousePkg/MousePkg.dsc
