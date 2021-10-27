#!/bin/bash

cd ~/go/src/github.ccs.neu.edu/sharon_CS5008/resources

git pull

cp -R [new folder] ~/go/src/github.ccs.neu.edu/sharon_CS5008/Lab/$1

echo "Copied folder from 'resources' to 'sharon-5008 $1"