#!/bin/bash

read -p "YES?" answer

if [ "Y" = $answer ] || [ "N" = "N" ]; then
	echo "You said Yes!"
else
	echo "You said no.."
fi
