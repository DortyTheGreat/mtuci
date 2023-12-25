from os import listdir
from os.path import isfile, join
mypath = 'C:\Torrent\Game of Thrones s03 (Amedia DUB)'
onlyfiles = [f for f in listdir(mypath) if isfile(join(mypath, f))]
print(onlyfiles)
import os
import subprocess


for file in onlyfiles:
    command = f"ffmpeg -y -i \"{mypath}\\{file}\" -c:v h264 -c:a aac \"{mypath}\\{'rc' + file}\""
    print(command)
    subprocess.call(command, shell=True)