#!/bin/bash
if [ $# -ne 3 ]; then
    echo "Usage: $0 all_set_file data_set_file query_set_file";
    exit -1;
fi
itemNum=15
i=0
rm -f $2
rm -f $3
while read line
do
    q=$(($i%$itemNum))
    if [ $q -lt 4 ]
    then
        echo $line >> $2;
    else
        echo $line >> $3;
    fi
    i=$(($i+1));
done < $1

