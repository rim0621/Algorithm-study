#!/bin/sh
git add *
contents="$(data+%Y)-$(data+%m)-$(data+%d)"
git commit -m contents

