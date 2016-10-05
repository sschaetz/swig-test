import diagswig

def test(swigged_arg, capsule_arg):
    print(swigged_arg)
    print(capsule_arg)
    x = diagswig.diag_consumer(swigged_arg)
    x.p()
    x.set_device(capsule_arg)
    x.p()
    swigged_arg.p()
