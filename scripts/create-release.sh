#!/bin/bash

set -x

if [ $# -ne 1 ]; then
    echo -e "\nUsage: $0 <TAG>\n"
    exit 1
fi

TAG=$1
RELEASE=NanoPlayBoard-$TAG.zip
TEMP=/tmp/NanoPlayBoard

echo "Creating release: $OUTPUT"

rm -rf $RELEASE
rm -rf $TEMP
mkdir -p $TEMP

cd ..
cp -R src $TEMP
cp -R examples $TEMP
cp -R experimental $TEMP
cp README.md $TEMP
cp keywords.txt $TEMP
cp library.properties $TEMP

cd $TEMP
find . -name "*.DS_Store" -type f -delete
cd ..
zip -r $RELEASE ./NanoPlayBoard