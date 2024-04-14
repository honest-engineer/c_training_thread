import java.text.SimpleDateFormat;
import java.util.Date;

public class Main {
    public static void main(String[] args) {
        outLog(new Object(){}.getClass().getEnclosingClass().getName());

        ThreadClsA threadA = new ThreadClsA();
        threadA.start();

        ThreadClsB threadB = new ThreadClsB();
        threadB.start();

        try {
            threadA.join();
            threadB.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    static class ThreadClsA extends Thread {
        public void run() {
            for (int i = 0; i < 2; i++) {
                try {
                    Thread.sleep(100);
                    outLog(new Object(){}.getClass().getEnclosingClass().getName());
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    static class ThreadClsB extends Thread {
        public void run() {
            for (int i = 0; i < 2; i++) {
                try {
                    Thread.sleep(150);
                    outLog(new Object(){}.getClass().getEnclosingClass().getName());
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    private static void outLog(String Cls) {
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss.SSS");
        String formatNowDate = sdf.format(new Date());
        System.out.println("CLS:" + Cls + " ID:" + Thread.currentThread().getId() + " Date:" + formatNowDate);
    }
}
