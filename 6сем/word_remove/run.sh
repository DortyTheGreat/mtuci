#! /usr/bin/env bash

OUT_DIR="wordremove_result"
NUM_REDUCERS=8

hdfs dfs -rm -r -skipTrash ${OUT_DIR}

yarn jar /usr/hdp/3.1.4.0-315/hadoop-mapreduce/hadoop-streaming.jar \
    -D mapreduce.job.reduces=${NUM_REDUCERS} \
    -D mapreduce.job.name="Streaming wordCount" \
    -files mapper.py,reducer.py \
    -mapper "python3 mapper.py" \
    -reducer "python3 reducer.py" \
    -input "/data/articles-sample" \
    -output ${OUT_DIR} > /dev/null

hdfs dfs -ls ${OUT_DIR}
hdfs dfs -cat ${OUT_DIR}/part-0000* | sort -k2nr | head -50
