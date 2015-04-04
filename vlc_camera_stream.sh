#!/bin/sh

raspivid -o - -t 0 -n -w 1280 -h 960 -fps 24 | cvlc -vvv stream:///dev/stdin --sout '#rtp{sdp=rtsp://:8554/}' :demux=h264
