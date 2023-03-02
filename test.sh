#!/bin/bash
build/bin/sai -g $1 | awk '{$1=""; print}'
exit ${PIPESTATUS[0]}
