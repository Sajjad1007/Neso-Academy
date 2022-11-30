//This program illustrates inheritance in Java.

package neso;

public class Test {

    public static void main(String[] args) {
        Account[] accounts = new Account[2]; //creating an array of two accounts
        accounts[0] = new SavingAccount(1, 1000, 4.5); //supertype variable is referring to a subtype variable
        accounts[0].withdraw(500);
        accounts[0].deposit(200);

        accounts[1] = new CurrentAccount(2, 2000, -200);
        accounts[0].withdraw(2300);

        System.out.println();
        System.out.println(accounts[0]); //toString() method of "SavingAccount" object is called
        System.out.println();
        System.out.println(accounts[1]); //toString() method of "CurrentAccount" object is called
    }

}