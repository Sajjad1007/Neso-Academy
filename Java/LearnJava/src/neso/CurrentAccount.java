package neso;

//A class to create accounts of current type
public class CurrentAccount extends Account { //"CurrentAccount" inherits the attributes and methods of "Account"

    private final double limitBelowZero; //the limit to what extent a user can withdraw money

    public CurrentAccount(int id, double balance, double limitBelowZero) {
        super(id, balance); //invoking superclass constructor is the first statement in the subclass constructor
        this.limitBelowZero = limitBelowZero;
    }

    //Overriding the withdraw() method of "Account" class
    @Override
    public boolean withdraw(double amount) {
        if(super.getBalance() - amount < limitBelowZero) return false;
        super.setBalance(super.getBalance() - amount);
        return true;
    }

    //Overriding the toString() method of "Account" class
    @Override
    public String toString() {
        return super.toString() + "\n" + "CurrentAccount (" +
                "limitBelowZero = " + limitBelowZero +
                ")";
    }

}