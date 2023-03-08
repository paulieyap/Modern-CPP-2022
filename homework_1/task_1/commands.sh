#!/bin/sh
wc -l < data.dat
grep -c 'dolor\|dalor' data.dat
wc -w  < data.dat
grep -E -c '\bmol' data.dat