import java.util.*;

public class methodDemo {
    public static void main(String[] args) {
      //设计一个加密方法，对数字字符串的每个数字+5后对10求余，最后反转
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入一个数字字符串：");
        String str = sc.nextLine();
        System.out.println("加密后的数字字符串为：" + encrypt(str));
    }
    public static String encrypt(String code)
    {
        StringBuilder sb = new StringBuilder(code);
        for(int i = 0; i < code.length(); i++)
        {
            int num = code.charAt(i) - '0';
             
            num = (num + 5) % 10;
            sb.setCharAt(i, (char)(num + '0'));
        }
        return sb.reverse().toString();
    }

}
