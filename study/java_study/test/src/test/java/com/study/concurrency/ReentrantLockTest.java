package com.study.concurrency;

import java.util.concurrent.locks.ReentrantLock;

public class ReentrantLockTest {
	 public static void main(String[] args) {
	        ReentrantLock lock = new ReentrantLock(true);  //1
	        lock.lock();  //2
	        try {
	            //do something
	        } finally {
	            lock.unlock(); //3
	        }
	    }

}
