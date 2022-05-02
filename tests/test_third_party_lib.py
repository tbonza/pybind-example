import scikit_build_example as m

def test_greeting():
    h = m.Hey(0,"bert")
    assert h.count == 0
    assert h.greeting == "bert"
