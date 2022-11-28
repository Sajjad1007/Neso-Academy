package com.NesoAcademy;

public class Main {

    public static void main(String[] args) {
        Client[] clients = new Client[2]; //creating an array of two clients

        clients[0] = new Client(100, "Sajjad", "123123123"); //instantiating a client
        clients[0].addAccount(new Account(1, 1000)); //passing a new "Account" object as a parameter
        clients[0].addAccount(new Account(2, 2000));

        clients[1] = new Client(200, "Ali", "456456789");
        clients[1].addAccount(new Account(1, 3000));
        clients[1].addAccount(new Account(2, 4000));
        clients[1].addAccount(new Account(3, 5000));

        System.out.println();
        System.out.println(clients[0].toString()); //unnecessary toString() call
        System.out.print(clients[1]);
    }

}
