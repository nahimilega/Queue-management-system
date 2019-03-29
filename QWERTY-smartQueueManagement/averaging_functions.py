    
def avgQueuelength():    
    f = open("length_of_queue.txt", "r")
    sum=0
    count=0
    for x in f:
        sum=sum+int(x[:1])
        count+=1
    avg=sum/count
    return avg

def avgTime():    
    f = open("time_spend_by_user.txt", "r")
    sum=0
    count=0
    minTime=99999999999
    maxTime=0
    for x in f:
        sum=sum+int(x)
        if(int(x)>maxTime):
        	maxTime=int(x)
        if(int(x)<minTime):
        	minTime=int(x)	
        count+=1
    avg=sum/count
    return avg,maxTime,minTime
