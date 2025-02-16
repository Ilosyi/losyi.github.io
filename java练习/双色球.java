import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Random;

public class methodDemo {
    public static void main(String[] args) {
        // 生成红球号码
        List<Integer> redBalls = generateRedBalls();
        // 生成蓝球号码
        int blueBall = generateBlueBall();

        // 输出红球号码
        System.out.print("红球号码: ");
        for (int redBall : redBalls) {
            System.out.printf("%02d ", redBall);
        }
        // 输出蓝球号码
        System.out.printf("\n蓝球号码: %02d", blueBall);
    }

    // 生成 6 个不重复的红球号码
    public static List<Integer> generateRedBalls() {
        List<Integer> allRedBalls = new ArrayList<>();
        // 初始化所有红球号码
        for (int i = 1; i <= 33; i++) {
            allRedBalls.add(i);
        }
        // 打乱红球号码顺序
        Collections.shuffle(allRedBalls, new Random());
        // 选取前 6 个号码作为中奖红球号码
        List<Integer> selectedRedBalls = allRedBalls.subList(0, 6);
        // 对选取的红球号码进行排序
        Collections.sort(selectedRedBalls);
        return selectedRedBalls;
    }

    // 生成 1 个蓝球号码
    public static int generateBlueBall() {
        Random random = new Random();
        // 生成 1 - 16 之间的随机数作为蓝球号码
        return random.nextInt(16) + 1;
    }
}
