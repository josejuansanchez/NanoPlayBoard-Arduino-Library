#!/usr/bin/env sh
set -evx

BOARD=$1

for EXAMPLE in "${PWD}/examples"/*/*/*.ino;
do
    arduino --verify --board ${BOARD} ${EXAMPLE}
done