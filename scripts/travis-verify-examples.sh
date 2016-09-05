#!/bin/bash
set -ev

BOARD=$1

for EXAMPLE in "../examples"/*/*/*.ino;
do
    arduino --verify --board ${BOARD} ${EXAMPLE}
done