package com.interview.system;
class MyThread implements Runnable{  
    private int ticket = 5;  
    public void run(){  
        for (int i=0;i<10;i++)  
        {  
            if(ticket > 0){  
                System.out.println("ticket = " + ticket--);  
            }  
        }  
    }  
}  

public class RunnableDemo1 {
	 public static void main(String[] args){  
	        MyThread my = new MyThread();  
	        new Thread(my).start();  
	        new Thread(my).start();  
	        new Thread(my).start();  
	    }  
}
