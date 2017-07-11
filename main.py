# https://github.com/google/python-fire/blob/master/doc/guide.md

import os

# case = 'normal' # normal / multiregion
# basedir = '.test/' + case

basedir = 'p2/'

dirs = os.listdir(basedir)

for files in dirs:
	print(files)

