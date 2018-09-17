n=input("Number: ")

l=len(n)
n1=0
n2=0

'''
Calculate product multiplied by 2
'''
if type(l/2)!=int:
    l1=l-1
    l2=l
else:
    l1=l
    l2=l-1

for i in range(1,l1,2):
    k=int(n[i])*2
    if  k >= 10:
        k=str(k)
        k1=int(k[0])
        k2=int(k[1])
        k=k1+k2
    n1=n1+k

'''
Calculate product not multiplied by 2
'''
for j in range(0,l2,2):
    m=int(n[j])
    n2=n2+m
no=str(n1+n2)
if int(no[-1])!=0:
    print('Invalid')
elif n[0:2]=='34' or n[0:2]=='37':
    print('AMEX')
elif n[0:2]==('51' or '52'or'53'or'54'or'55' ):
    print('MASTER')
elif n[0]=='4':
    print('VISA')
