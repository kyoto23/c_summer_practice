def Q( x , y ) :
if x*y != 0: 
  q.add((x*y<0)+2*(y<0))
x,y,X,Y=map(int,input() .split())
if x==X==0 or y==Y==0:
 print(0) ; exit()
q=set()
Q(x, y)
Q(X,Y)
if X-x!=0 and Y-y!=0 and x*Y<=0 and y*Y<=0:
 C=x*Y-y*X
 Q(C/(Y-y) ,C/ ( x-X) )
for i in sorted (list(q)):print(i +1)
