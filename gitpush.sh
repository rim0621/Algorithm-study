#!/bin/sh
git add *
content=$(date '+%Y-%m-%d')
git commit -m  $content
git push -u origin master
id="rim0621"
echo $id
