package com.NesoAcademy;

import java.util.Scanner;

//this program only uses the "Account" class
public class Sajjad {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println();
        System.out.println("Enter the account's information: ");

        //recording account information from the user
        System.out.print("Account id = ");
        int id = input.nextInt();
        System.out.print("Account balance = ");
        double balance = input.nextDouble();

        Account testAccount = new Account(id, balance);
        System.out.println();

        System.out.print("How much to withdraw? ");
        if(testAccount.withdraw(input.nextDouble())) {
            System.out.println("Withdraw successful.");
        }
        else {
            System.out.println("You have not enough money to withdraw.");
        }

        System.out.print("How much to deposit? ");
        testAccount.deposit(input.nextDouble());
        System.out.println("Deposit successful.");
        System.out.println();

        System.out.println("The current account information: ");
        System.out.println("Account created : " + testAccount.getDateCreated());
        System.out.println("Account id = " + testAccount.getId());
        System.out.println("Account balance = " + testAccount.getBalance());
    }

}