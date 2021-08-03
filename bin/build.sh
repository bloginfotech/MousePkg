#!/bin/bash
cd /home/jeff/edk/latest/edk2
. edksetup.sh

build -a X64 -t GCC5 -p /home/jeff/wrk/MousePkg/MousePkg.dsc

