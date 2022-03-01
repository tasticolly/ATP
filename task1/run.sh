#!/bin/bash

while [ -n "$1" ]
do
case "$1" in
"--input_folder") INPUT_FOLDER="$2" 
shift;;
"--extension") EXTENSION="$2"
shift;;
"--backup_folder") BACKUP_FOLDER="$2"
shift;;
"--backup_archive_name") BACKUP_ARCHIVE_NAME="$2"
shift;;
esac
shift
done
ORIGIN_DIR=$(pwd)
mkdir $BACKUP_FOLDER
cd $BACKUP_FOLDER
BACKUP_FOLDER=$(pwd)
cd $ORIGIN_DIR
cd $INPUT_FOLDER
for x in $(find . -name "*.$EXTENSION") #| xargs mkdir -p && xargs cp $BACKUP_FOLDER/backup_folder
do
mkdir -p $BACKUP_FOLDER/$(dirname $x)
cp $x $BACKUP_FOLDER/$x
done
tar -czf $BACKUP_FOLDER/../$BACKUP_ARCHIVE_NAME $BACKUP_FOLDER 2>"/dev/null"
echo "done"

#mkdir $BACKUP_FOLDER
#find  $INPUT_FOLDER -name "*.$EXTENSION" | xargs cp --parents -t $BACKUP_FOLDER
#tar -czf $BACKUP_ARCHIVE_NAME $BACKUP_FOLDER

