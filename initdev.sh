#!/bin/bash

sudo modprobe brd
sudo mkfs.ext2 /dev/ram0
sudo mount /dev/ram0 mnt
