#!/bin/sh
git add *
content='data+%Y-%m-%d'

git commit -m $content
git push -u origin master

