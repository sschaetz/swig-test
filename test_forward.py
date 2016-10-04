import sys
sys.path.append('/Users/sschaetz/.pyenv/versions/chips-3.4.3/lib/python3.4/site-packages/')

import ipdb

def test(arg):
    print(arg)
    ipdb.set_trace()
    print("haha")
    print(arg)
    print("nono")
    print(arg.__dict__)

