#!/bin/sh
git add *
content=$(date '+%Y-%m-%d')
id='rim0621'
echo $content
echo $id

git commit -m  $content
git push -u origin master
if[$a -eq Username for 'https://github.com'];
then
echo "rim0621"
