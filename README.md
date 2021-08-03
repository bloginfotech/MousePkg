# test_mouse_efi
projet efi pour tester la souris
pour construire le projet:

modifier la derniére ligne du fichier MousePkg.dsc : mettre le chemin absolu vers le fichier mouse.inf 

cd <installation d'edk2>

. edksetup.sh

git clone https://

build -a X64 -t GCC5 -p MousePkg/MousePkg.dsc
