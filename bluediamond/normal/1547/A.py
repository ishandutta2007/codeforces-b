for s in''.join(open(0)).split('\n\n')[1:]:a,b,c,d,e,f=map(int,s.split());print(abs(a-c)+abs(b-d)+2*((a==c==e)*(b-f)*(d-f)|(b==d==f)*(a-e)*(c-e)<0))