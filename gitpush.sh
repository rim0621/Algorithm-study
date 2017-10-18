#!/bin/sh
git add *
content=$(date '+%Y-%m-%d')
id='rim0621'
echo $content
echo $id

git commit -m  $content
read a |  git push -u origin master

