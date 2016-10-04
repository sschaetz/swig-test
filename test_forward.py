import diagswig

def test(arg):
    print(arg)
    x = diagswig.diag_consumer(arg)
    x.p()
    arg.p()
