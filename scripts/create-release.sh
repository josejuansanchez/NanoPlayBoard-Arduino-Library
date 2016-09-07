#!/bin/bash
set -x

if [ $# -ne 1 ]; then
    echo -e "\nUsage: $0 <TAG>\n"
    exit 1
fi

TAG=$1
RELEASE=NanoPlayBoard-$TAG.zip
SOURCES=/tmp/NanoPlayBoard

# Remove old sources
rm -rf $SOURCES
mkdir -p $SOURCES

# Copy sources into a temporary folder
cd ..
cp -R src $SOURCES
cp -R examples $SOURCES
cp -R experimental $SOURCES
cp README.md $SOURCES
cp keywords.txt $SOURCES
cp library.properties $SOURCES

# Remove temporary files
cd $SOURCES
find . -name "*.DS_Store" -type f -delete

# Create .zip file
cd ..
zip -r $RELEASE ./NanoPlayBoard
