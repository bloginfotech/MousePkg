#!/bin/bash
INFNAME=`grep /home/jeff/wrk/MousePkg/*.inf /home/jeff/wrk/MousePkg/MousePkg.dsc`
EFINAME=`grep BASE_NAME $INFNAME | cut -f2 -d'=' |sed 's/ //g'`


cp "/home/jeff/wrk/MousePkg/$EFINAME/DEBUG/$EFINAME.efi" ~/wrk/test/


