# https://github.com/google/python-fire/blob/master/doc/guide.md

import parse_files

# CONFIGURATION
CASE = 'normal' # normal / multiregion
BASEDIR = './test/'

print(parse_files.get_temps(CASE, BASEDIR))