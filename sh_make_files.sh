#!/bin/bash

make -C submit_pushswap
make -C submit_checker
cp submit_pushswap/push_swap push_swap
cp submit_checker/checker checker
