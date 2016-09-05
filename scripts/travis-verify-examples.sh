#!/bin/bash
set -ev
for EXAMPLE in "../examples"/*/*/*.ino;
do
    arduino --verify --board ${BOARD} ${EXAMPLE}
done