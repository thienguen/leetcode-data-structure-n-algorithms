package Nganhang;

import java.text.NumberFormat;

public class BankAccount {

    private String tentk;
    private String sotk;
    private double so_du;

    // sotk must have exact 10 numbers
    public BankAccount(String tentk, String sotk, double so_du) {
        
        this.tentk = tentk;
        
        this.sotk  = sotk;
        
        if (so_du >= 0) {
            this.so_du = so_du;
        } else {
            this.so_du = 0;
        }
    }

    public BankAccount(String tentk, String sotk) {
        this.tentk = tentk;
        this.sotk = sotk;
        this.so_du = 0;
    }

    public BankAccount() {
        this.tentk = "";
        this.sotk = "";
        this.so_du = 0;
    }

    public String getTentk() {
        return this.tentk;
    }

    public String getSotk() {
        return this.sotk;
    }

    public double getSo_du() {
        return this.so_du;
    }

    public void setTentk(String tentk) {
        this.tentk = tentk;
    }

    public void setSotk(String sotk) {
        this.sotk = sotk;
    }

    public void setSo_du(double so_du) {
        this.so_du = so_du;
    }

    @Override
    public String toString() 
    {
        NumberFormat EN = NumberFormat.getCurrencyInstance();
        String str      = EN.format(this.so_du);
        // return "Tên tài khoản: " + this.tentk + "\n" +
        //        "Số tài khoản: " + this.sotk + "\n" +
        //        "Số dư: " + str;
        return "BA:" + this.tentk + ":" + this.sotk + ":" + str;
    }

    public void naptien(double so_tien) {
        if (so_tien >= 0) {
            this.so_du += so_tien - (so_tien * 0.01);
        }
    }

    public void ruttien(double so_tien) {
        if (so_tien >= 0 
            && this.so_du >= so_tien + (0.01 * so_tien)) {
            this.so_du -= so_tien + (0.01 * so_tien);
        }
    }

    


}

