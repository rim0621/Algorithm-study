#!/bin/sh
git add *
content=$(date '+%Y-%m-%d')
id='rim0621'
echo $content
echo $id

git commit -m  $content
git push -u origin master
expect "userID:" {send "rim0621\r"}
