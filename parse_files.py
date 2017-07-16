import os
from toolz.functoolz import compose
from toolz import curry
from toolz.curried import filter, map

get_case_dir = lambda basedir: lambda case : basedir + case + '/' # curried

max_dir = compose(
    str, #std
    lambda number: int(number) if number == int(number) else number, # parse_zero
    max, #std
    map(float), # list_to_float
    filter(lambda e: e.isdigit()), # only_numbers
    os.listdir # std
)

gen_temp_path = lambda path: path + max_dir(path) + '/T'

@curry
def get_temps(basedir, case):
    base_path = get_case_dir(basedir)(case)
    temp_path = gen_temp_path(base_path)
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
    print(get_temps(BASEDIR)(CASE)[0])

if __name__ == '__main__':
    main()