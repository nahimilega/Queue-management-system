

import matplotlib.pyplot as plt 

'''
import datetime 

x = datetime.datetime.now()

#%w	Weekday as a number 0-6, 0 is Sunday
#%m	Month as a number 01-12	12
#%H	Hour 00-23
#%M	Minute 00-59


day=x.strftime("%w")
date=x.strftime("%d")
month=x.strftime("%m")
hour=x.strftime("%H")
minute=x.strftime("%M")

final="-"+str(date)+":"+str(month)+":"+str(date)+":"+str(hour)+":"+str(minute)

#-04:03:04:16:12
print(final)
'''






def dayGraph():
    '''
    It generates the graph of day(x axis) vs length of queue (y axis) 
    '''
    f = open("length_of_queue.txt", "r")
    length_of_queue=[]
    day=[]
    date=[]
    month=[]
    hour=[]
    minute=[]
    for x in f:
        length_of_queue.append(int(x[:1]))
        day.append(int(x[2:4]))
        date.append(int(x[5:7]))
        month.append(int(x[8:10]))
        hour.append(int(x[11:13]))
        minute.append(int(x[14:16]))

    final_y_axis=[0,0,0,0,0,0,0]
    list_of_count_for_particular_day=[0,0,0,0,0,0,0]


    for i in range(len(day)):
        final_y_axis[day[i]]=final_y_axis[day[i]]+length_of_queue[i]
        list_of_count_for_particular_day[day[i]]+=1

    for j in range(len(list_of_count_for_particular_day)):
        if(list_of_count_for_particular_day[j]!=0):# To prevent divide by 0 if no data of that day available
            final_y_axis[j]=final_y_axis[j]/list_of_count_for_particular_day[j]


    plt.plot(['Sun','Mon','Tue','Wed','Thus','Fri','Sat'], final_y_axis, label = "line 1") 
    plt.xlabel('day') 
    
    plt.ylabel('length_of_queue') 
    plt.legend()  
    plt.savefig('day_Graph.png')
    

def hourGraph():
    """
    It generates the graph of hour(x axis) vs length of queue (y axis)
    """
    f = open("length_of_queue.txt", "r")
    length_of_queue=[]
    day=[]
    date=[]
    month=[]
    hour=[]
    minute=[]
    for x in f:
        length_of_queue.append(int(x[:1]))
        day.append(int(x[2:4]))
        date.append(int(x[5:7]))
        month.append(int(x[8:10]))
        hour.append(int(x[11:13]))
        minute.append(int(x[14:16]))
    
    final_y_axis=[]
    list_of_count_for_particular_hour=[]
    for i in range(23):
        final_y_axis.append(0)
        list_of_count_for_particular_hour.append(0)

    for i in range(len(hour)):
        final_y_axis[hour[i]]=final_y_axis[hour[i]]+length_of_queue[i]
        list_of_count_for_particular_hour[hour[i]]+=1    

    for j in range(len(list_of_count_for_particular_hour)):
        if(list_of_count_for_particular_hour[j]!=0):# To prevent divide by 0 if no data of that day available
            final_y_axis[j]=final_y_axis[j]/list_of_count_for_particular_hour[j]    
    x_axis=[]
    for i in range(23):
        x_axis.append(i)


    plt.plot(x_axis, final_y_axis, label = "line 1") 
    plt.xlabel("Hour") 
    plt.ylabel('length_of_queue') 
    plt.legend()  
    plt.savefig('hour_Graph.png') #To save as image
    



hourGraph()