import java.util.ArrayList;
import java.util.Scanner;
import java.util.Random;

public class ATM {
    private final ArrayList<Account> accounts = new ArrayList<Account>();
    private final Scanner sc = new Scanner(System.in);

    //启动ATM系统，展示欢迎界面
    public void start() {
        while (true) {
            System.out.println("欢迎使用ATM系统");
            System.out.println("1.登录");
            System.out.println("2.注册");
            System.out.println("3.退出");
            System.out.println("请选择：");
            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    login();
                    break;
                case 2:
                    register();
                    break;
                case 3:
                    System.out.println("谢谢使用");
                    //结束程序
                    return;
                default:
                    System.out.println("输入有误，请重新输入");
            }
        }
    }

    private void register() {
        //1.创建一个账户
        Account acc = new Account();
        System.out.println("请输入用户名：");
        acc.setUserName(sc.next());
        while (true) {
            System.out.println("请输入密码：");//判断两次
            String passWord1 = sc.next();
            System.out.println("请再次输入密码：");
            String passWord2 = sc.next();
            if (passWord1.equals(passWord2)) {
                acc.setPassWord(passWord1);
                break;
            } else {
                System.out.println("两次密码不一致，请重新输入");
            }
        }

        while (true) {
            System.out.println("请输入性别：");//判断输入的性别是否正确
            String sex = sc.next();
            if (sex.equals("男") || sex.equals("女")) {
                acc.setSex(sex);
                break;
            } else {
                System.out.println("输入有误，请重新输入");
            }
        }
        System.out.println("请输入取现额度：");
        acc.setLimit(sc.nextDouble());
        // 2.由系统生成一个卡号且不能与其他账户重复
        String cardId = generateUniqueCardId();
        acc.setCardId(cardId);


        //3.添加到账户集合
        accounts.add(acc);
        System.out.println("恭喜您" + acc.getUserName() + "开户成功" +
                "您的卡号为：" + acc.getCardId());

    }

    private void login() {
        // 1. 检查是否有账户
        if (accounts.isEmpty()) {
            System.out.println("当前没有账户，请先注册");
            return;
        }

        // 2. 输入卡号
        System.out.print("请输入卡号：");
        String cardId = sc.next();
        Account acc = getAccountByCardId(cardId);

        // 检查卡号是否存在
        if (acc == null) {
            System.out.println("卡号不存在，请重新登录");
            return;
        }

        // 3. 输入密码（最多尝试3次）
        int attempts = 3;
        while (attempts > 0) {
            System.out.print("请输入密码（剩余尝试次数：" + attempts + "）：");
            String passWord = sc.next();

            if (acc.getPassWord().equals(passWord)) {
                System.out.println(acc.getUserName() + " 登录成功");
                operation(acc);
                return;
            } else {
                attempts--;
                System.out.println("密码错误，剩余尝试次数：" + attempts);
            }
        }

        // 4. 三次密码错误后强制退出
        System.out.println("连续三次密码错误，退出登录");
    }

    private Account getAccountByCardId(String cardId) {
        for (Account acc : accounts) {
            if (acc.getCardId().equals(cardId)) {
                return acc;
            }
        }
        return null;
    }

    /**
     * 生成唯一的19位中国银行卡号
     * 格式：622588XXXXXXXXXXXXX9（前6位固定，中间13位随机，最后1位校验位）
     */
    private String generateUniqueCardId() {
        Random rand = new Random();
        String cardId;
        do {
            StringBuilder sb = new StringBuilder("622588"); // 固定前6位BIN
            for (int i = 0; i < 13; i++) {
                sb.append(rand.nextInt(10)); // 随机生成中间13位
            }
            sb.append(calculateLuhnCheckDigit(sb.toString())); // 计算校验位
            cardId = sb.toString();
        } while (isCardIdExists(cardId)); // 检查卡号是否唯一
        return cardId;
    }

    /**
     * 检查卡号是否已存在
     */
    private boolean isCardIdExists(String cardId) {
        for (Account acc : accounts) {
            if (acc.getCardId().equals(cardId)) {
                return true;
            }
        }
        return false;
    }

    /**
     * 使用Luhn算法计算校验位
     */
    private int calculateLuhnCheckDigit(String cardNumber) {
        //校验规则为：从卡号最后一位数字开始，逆向将奇数位数字（1、3、5等等）相加。
        int sum = 0;
        boolean alternate = false;
        for (int i = cardNumber.length() - 1; i >= 0; i--) {
            int n = Integer.parseInt(cardNumber.substring(i, i + 1));
            if (alternate) {
                n *= 2;
                if (n > 9)
                    n = (n % 10) + 1;
            }
            sum += n;
            alternate = !alternate;
        }
        int mod = sum % 10;
        return (mod == 0) ? 0 : 10 - mod;
    }

    private void operation(Account acc) {
        // 这里可以实现账户的各种操作，如查询余额、取款、存款等
        System.out.println("欢迎回来，" + acc.getUserName() + "。您的卡号为：" + acc.getCardId());
        // 示例操作
        while (true) {
            System.out.println("===请选择操作===");
            System.out.println("1.查询账户信息");
            System.out.println("2.取款");
            System.out.println("3.存款");
            System.out.println("4.转账");
            System.out.println("5.修改密码");
            System.out.println("6.退出登录");
            System.out.println("7.注销账户");

            int choice = sc.nextInt();
            switch (choice) {
                case 1:
                    showInfo(acc);
                    break;
                case 2:
                    withdraw(acc);
                    break;
                case 3:
                    deposit(acc);
                    break;
                case 4:
                    transfer(acc);
                    break;
                case 5:
                    changePassword(acc);
                    break;
                case 6:
                    System.out.println("退出登录");
                    return;
                case 7:
                    deleteAccount(acc);
                    break;
                default:
                    System.out.println("输入有误，请重新选择");
            }
        }
    }
    private void showInfo(Account acc){
        System.out.println("用户名："+acc.getUserName());
        System.out.println("性别："+acc.getSex());
        System.out.println("余额："+acc.getMoney());
        System.out.println("取现额度："+acc.getLimit());
    }
    private void deposit(Account acc){
        System.out.println("请输入存款金额：");
        double money = sc.nextDouble();
        acc.setMoney(acc.getMoney()+money);
        System.out.println("存款成功，当前余额："+acc.getMoney());
    }
    private void withdraw(Account acc){
        System.out.println("请输入取款金额：");
        double money = sc.nextDouble();
        if(money>acc.getMoney()){
            System.out.println("余额不足，取款失败");
        }else if(money>acc.getLimit()){
            System.out.println("超过取现额度，取款失败");
        }else{
            acc.setMoney(acc.getMoney()-money);
            System.out.println("取款成功，当前余额："+acc.getMoney());
        }
    }
    private void transfer(Account acc){
        System.out.println("请输入对方卡号：");
        String cardId = sc.next();
        Account target = getAccountByCardId(cardId);
        if(target==null){
            System.out.println("对方卡号不存在，转账失败");
            return;
        }
        System.out.println("请输入转账金额：");
        double money = sc.nextDouble();
        if(money>acc.getMoney()){
            System.out.println("余额不足，转账失败");
        }else{
            acc.setMoney(acc.getMoney()-money);
            target.setMoney(target.getMoney()+money);
            System.out.println("转账成功，当前余额："+acc.getMoney());
        }
    }
    //修改密码
    private void changePassword(Account acc){
        System.out.println("请输入原密码：");
        String oldPassword = sc.next();
        if(!oldPassword.equals(acc.getPassWord())){
            System.out.println("原密码错误，修改失败");
            return;
        }
        //新密码，要求输入两次
        while(true){
            System.out.println("请输入新密码：");
            String newPassword1 = sc.next();
            System.out.println("请再次输入新密码：");
            String newPassword2 = sc.next();
            if(newPassword1.equals(newPassword2)){
                acc.setPassWord(newPassword1);
                System.out.println("密码修改成功");
                return;
            }else{
                System.out.println("两次密码不一致，请重新输入");
            }
        }
    }
    //注销账户
    private void deleteAccount(Account acc){
        accounts.remove(acc);
        System.out.println("账户注销成功");
    }
}
