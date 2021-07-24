# Producer Consumer Problem
# Description: The producer-consumer problem arises when a process is producing some data, the producer, and another process is using that data, the consumer. The producer and the consumer, however, could be operating at different rates, ie the consumer could be using data quicker than the producer can produce it. To support this we need to offer a queue structure for the producer to place data onto and the consumer to take from and also a count of how many items exist on the queue, so producers cannot place too much data on the queue and consumers do not try and take data that is not there.


# Since producers and consumers are running at the same time we will use thread. For this, we will import Semaphore, Thread from threading module in Python. 


from threading import Thread, Semaphore
import time
import random       

queue = []         #queue from where producer will produce data and consumer will
                   consume data
MAX_NUM = 10       #max limit of the queue

sem = Semaphore()  #intitializing semaphore

class ProducerThread(Thread):
    def run(self):
        nums = range(5) # [0 1 2 3 4]
        global queue
        
        while True:
            sem.acquire()  #wait operation to stop consuming 
            if len(queue) == MAX_NUM:
                
                print ("List is full, producer will wait")
                sem.release() #signal operation only when when queue is full and 
                  allow consumer to consume data
                print ("Space in queue, Consumer notified the producer")

            num = random.choice(nums) 
            queue.append(num) #added any random number from 0 to 4 to the list
            print ("Produced", num) 
            sem.release() #signal operation to allow consumer to consume data

            time.sleep(random.random()) #to allow program to run a bit slower 

class ConsumerThread(Thread):
    def run(self):
        global queue
        
        while True:
            sem.acquire()   #wait operation to stop producing
            if not queue:
                print ("List is empty, consumer waiting")
                sem.release()  #signal operation only when when queue is empty and allow
                               producer to produce data
                print ("Producer added something to queue and notified the consumer")

            num = queue.pop(0)
            
            print ("Consumed", num)
            sem.release()  #signal operation to allow producer to produce

            time.sleep(random.random())

def main():
    ProducerThread().start()    #start producer thread
    ConsumerThread().start()    #start consumer thread

if __name__ == '__main__':
    main()