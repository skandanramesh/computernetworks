#!/usr/bin/bash

sudo apt update

sudo apt install g++ python3 cmake 
sudo apt install python3-dev pkg-config sqlite3 python3-setuptools
sudo apt install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools

wget http://www.nsnam.org/release/ns-allinone-3.36.1.tar.bz2
tar xjf ns-allinone-3.36.1.tar.bz2

cd ns-allinone-3.36.1
./build.py

cd ns-3.36.1
./ns3 configure --enable-tests --enable-examples -d optimized
./test.py

./ns3 configure --build-profile=debug --enable-examples --enable-tests
./ns3
./ns3 run hello-simulator
