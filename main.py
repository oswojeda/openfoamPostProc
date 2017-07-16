# https://github.com/google/python-fire/blob/master/doc/guide.md

from parse_files import get_temps

# CONFIGURATION
CASE = 'normal' # normal / multiregion
BASEDIR = './test/'

first_temp = get_temps(BASEDIR)(CASE)
print(first_temp)