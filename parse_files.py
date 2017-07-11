import os
from toolz.functoolz import compose


def get_case_dir(case, basedir):
    return basedir + case + '/'


def getdirs(case, basedir):
    dirs = os.listdir(get_case_dir(case, basedir))
    return dirs


list_to_float = lambda l: map(float, l)


def parse_zero(number):
    if(number == int(number)):
        return int(number)
    else:
        return number


getMaxNumber = compose(
    str,
    parse_zero,
    max,
    list_to_float
)

def gen_temp_path(case, basedir):
    # directorios
    dirs = [file for file in getdirs(case, basedir) if file.isdigit()]
    temp_path = get_case_dir(case, basedir) + getMaxNumber(dirs) + '/T'
    return temp_path




def get_temps(case, basedir):
    temp_path = gen_temp_path(case, basedir)
    temps = []
    with open(temp_path, 'r') as temp_file:
        list_length = 0
        for key, line in enumerate(temp_file):
            if (key == 23):
                list_length = int(line.strip())
            if (key >= 25):
                temps.append(float(line.strip()))
            if (key >= 25 + list_length - 1):
                break
    return temps

def main():
    # CONFIGURATION
    CASE = 'normal' # normal / multiregion
    BASEDIR = './test/'
    # Just for simple testing
    print(get_temps(CASE, BASEDIR)[0])

if __name__ == '__main__':
    main()