import java.util.*;

public class DiningPhilosophers {
     public static void main(String[] args) throws Exception {
        final Philosopher[] philosophers = new Philosopher[5];
        Object[] forks = new Object[philosophers.length];
 
        for (int i = 0; i < forks.length; i++) {
            forks[i] = new Object();
        }
 
        for (int i = 0; i < philosophers.length; i++) {
            Object leftFork = forks[i];
            Object rightFork = forks[(i + 1) % forks.length];
 			Random rand = new Random();

	        if(i == rand.nextInt(1)%5)
                // The last philosopher picks up the right fork first
                philosophers[i] = new Philosopher(leftFork, rightFork);
			else
                philosophers[i] = new Philosopher(rightFork, leftFork); 

            Thread t = new Thread(philosophers[i], "Philosopher " + (i + 1));
            t.start();
        }
    }
}

class Philosopher implements Runnable {
    private Object leftFork;
    private Object rightFork;
    private Boolean eaten;
 
    public Philosopher(Object leftFork, Object rightFork) {
        this.leftFork = leftFork;
        this.rightFork = rightFork;
		eaten = false;
    }

    private void doAction(String action) throws InterruptedException {
        System.out.println(Thread.currentThread().getName() + " " + action);
        Thread.sleep(((int) (Math.random() * 100)));
    }

    public void run() {
        try {
            while (true) {
                // thinking
                doAction(": Thinking");
                synchronized (leftFork) {
                    doAction(": Picked up left fork");
                    synchronized (rightFork) {
                        // eating
						eaten = true;
                        doAction(": Picked up right fork - eating"); 
                        doAction(": Put down right fork");
                    }
                    // Back to thinking
                    doAction(": Put down left fork. Back to thinking");
                }
            }
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
            return;
        }
    }
}
