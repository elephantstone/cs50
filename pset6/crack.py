import crypt
import sys
import string

'''
create a list containing all the upper and lower case characters
'''


l1 =['']
l2 = [i for i in string.ascii_letters]
li =l1+l2
print(li)

def main():
    '''
    hashed is the hashed password to be cracked
    '''
    if len(sys.argv)!=2:
        raise IndexError

    l1 =['']
    l2 = [i for i in string.ascii_letters]
    li =l1+l2
    print(li)
    hashed=sys.argv[1]
    salt=hashed[0:2]
    word=''

    for i in li:
        for j in li:
            for k in li:
                for l in li:
                    word=i+j+k+l
                    word=str(word)
                    if crypt.crypt(word,salt)==hashed:
                        print(word)
                        return word
if __name__ == "__main__":
    main()
