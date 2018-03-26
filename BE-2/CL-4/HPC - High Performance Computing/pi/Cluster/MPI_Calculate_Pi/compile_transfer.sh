#!/bin/bash

mpicc $2
rsync -a --progress $1 $3:~/