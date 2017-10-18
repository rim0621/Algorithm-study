#!/bin/sh
git add *
content=$(date '+%Y-%m-%d')
id='rim0621'
echo $content
echo $id

git commit -m  $content
git push -u origin master
rim0621
