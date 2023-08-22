#!/bin/bash
# maxpid.sh - Displays max pid value
#run

pid_max=$(cat /proc/sys/kernel/pid_max)
echo "Maximum PID value: $pid_max"
