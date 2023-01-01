import Nganhang.*;

public class App
{
    public static void main(String[] args)
    {
        BankAccount account = new BankAccount("Thien Nguyen", "123456789", 100000);
        System.out.println(account.getTentk());
        System.out.println(account.getSotk());
        System.out.println(account.getSo_du());
        System.out.println(account.toString());

        

    }

}