#!/bin/bash

n=`cat ./query_set_file | wc -l`
interval=11
for((i=0; i<n; ++i))
do
    expr ${i} / ${interval}
done
