#!/bin/bash
TEXT=`python3 -c "print('${1}' * ${2})"`
PID=`ps | grep ./server | grep -v grep | awk '{print $1}'`

./client $PID $TEXT
