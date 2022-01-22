# try:
#     assert 2 == 3
# except AssertionError:
#     print("Blah")

try:
    if 2 < 3: raise Exception('Essential Repeat.')
except Exception:
    print('Essential Repeat')

    