flag = "01101001011011110101010001111011001101100110001001110100010111110110111001110100001101000101111101100110001110000011001000110110001101000011001001111101"
#flag = "ioT{6bt_nt4_f82642}"
#flag = 灩捯䍔䙻ㄶ形楴獟楮獴㌴摟潦弸弲㘶㠴挲ぽ
'''print(''.join([chr((ord(flag[i]) >> 8) - ord(flag[i - 1])) for i in range(0, len(flag), 2)]))'''

for i in range(0,len(flag)):
    print(chr(ord(flag[i])))


def main():
    encoded_string = "灩捯䍔䙻ㄶ形楴獟楮獴㌴摟潦弸弲㘶㠴挲ぽ"
    for i in range(len(encoded_string)):
        print(chr(ord(encoded_string[i])>>8))
        print(chr((ord(encoded_string[i]))-((ord(encoded_string[i])>>8)<<8)))
        print (i)


main()

p
i

c
o

C
T

F
{

1
6

_
b

i
t

s
_

i
n

s
t

3
4

d
_

o
f

_
8

_
2

6
6

8
4

c
2

0
}
