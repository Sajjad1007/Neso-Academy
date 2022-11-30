package neso;

import java.util.Date;

//A class to create accounts of a client
public class Account { //directly extends "Object" class of Java

    private int id; //account id
    private double balance; //account initial balance
    private final Date dateCreated; //account creation time and data

    public Account(int id, double balance) {
        dateCreated = new Date();
        this.id = id;
        this.balance = balance;
    }

    //To withdraw amount from the account
    public boolean withdraw(double amount) {
        if(amount <= balance) {
            balance -= amount;
            return true;
        }
        else return false;
    }

    //To deposit amount to the account
    public void deposit(double amount) {
        balance += amount;
    }

    //Overriding the toString() method of "Object" class
    @Override
    //Returning the string representation of the object
    public String toString() {
        return id + ". " + balance + "  " + dateCreated;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public Date getDateCreated() {
        return dateCreated;
    }

}