import java.util.*;

public class methodDemo {
    public static void main(String[] args) {
       //生成指定位数的随机验证码，包括数字，大小写字母
        int length;
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入验证码位数：");
        length = sc.nextInt();
        String result = generateRandomString(length);

    }
    public static String generateRandomString(int length) {
        String str = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        Random random = new Random();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < length; i++) {
            int number = random.nextInt(62);
            sb.append(str.charAt(number));//返回指定索引处的 char 值并添加到StringBuffer对象
        }
        System.out.println(sb);//返回此序列中数据的字符串表示形式。
        return sb.toString();
    }
}
