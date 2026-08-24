"""
a , b , c = 1 ,2 ,3
name = input ('what is your name ?')
x , y ,z = input().split()
print("hi",c ,name,z)

listt = [-2, -3 , -4]
x, y , z = map (int , listt)
print(x ** 2, y//z , z,7 in listt)

*---------------------------------------------*
Exercise 01

name = input('enter your name ')
p1 , p2 ,p3 = map (int ,input('enter prices of the three products').split())
sum = p1 + p2 + p3
discount = sum * 0.90
print('hey',name ,'the price after the discount is',discount)
*---------------------------------------------*

colors = ['red','green','yellow']
for index , color in enumerate(colors):
    print (index,color)

hello = "hello"
for i in range(len(hello)):
    print(i ,hello[i] )

*---------------------------------------------*
Exercise 02

p1 , p2 ,p3 = map (int ,input('enter prices of the three products').split())
listt = [p1 , p2 , p3]
for _ in listt :
    if _ > 0 and _ < 50 :
        print(_ , 'is cheap')
    elif _ > 50 and _ < 100 :
        print(_ , 'is mid')
    elif _ > 100 :
        print(_ ,'is expensive')
*---------------------------------------------*
s = 'python'

print(s[::-2])
print('**hi**'.strip('*'))
print("*".join(['a','b','c']))
print('apple'.replace('p','b'))
print('hello'* 4)
text = 'waleed'
print('m'+text[1:])
print('hi %s'% text)
print('hi'+ text)

*---------------------------------------------*
Exercise 03











*---------------------------------------------*



"""

even_word = input('enter a even length word')
for index,later in enumerate(even_word) :
    if index % 2 != 0 :
        even_word = even_word.replace(later,'')
even_word = even_word[:len(even_word)//2]+even_word[:(len(even_word)//2):-1]
print(even_word)
