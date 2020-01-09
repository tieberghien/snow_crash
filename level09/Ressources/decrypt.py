import sys

string = sys.argv[1]
key = 0
result = ''
for char in string:
    result += chr(ord(char) + key)
    key -= 1
print('{res}'.format(res = result))
