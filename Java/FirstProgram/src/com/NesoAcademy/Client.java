package com.NesoAcademy;

import java.util.ArrayList;

//this is a class to create clients
public class Client {

    private int id; //client id
    private String name; //client name
    private String phone; //client phone number
    private final ArrayList<Account> accounts; //this ArrayList is a field of Client class

    public Client(int id, String name, String phone) {
        accounts = new ArrayList<>(); //this ArrayList will contain all accounts of a client
        this.id = id;
        this.name = name;
        this.phone = phone;
    }

    //adding an account to client's profile
    public void addAccount(Account account) {
        accounts.add(account);
    }

    //removing an account from clients profile
    public boolean removeAccount(int accountId) {
        for(Account account : accounts) {
            if(account.getId() == accountId) {
                accounts.remove(account);
                return true;
            }
        }

        return false;
    }

    //overriding the toString() method of "Object" class
    @Override
    public String toString() {
        String str = "Client details :\n";
        str = str + id + "  " + name + "  " + phone + "\n";

        for(Account account : accounts) {
            str += account.toString() + "\n"; //here we can also use s += account + "\n"
        }

        return str;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

}
