package neso;

//A class to create accounts of saving type
public class SavingAccount extends Account { //"SavingAccount" inherits the attributes and methods of "Account"

    private double annualInterestRate; //accounts of saving type provides interests to the user

    public SavingAccount(int id, double balance, double annualInterestRate) {
        super(id, balance); //invoking superclass constructor is the first statement in the subclass constructor
        this.annualInterestRate = annualInterestRate;
    }

    public double getAnnualInterestRate() {
        return annualInterestRate;
    }

    public void setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
    }

    //Overriding the toString() method of "Account" class
    @Override
    public String toString() {
        return super.toString() + "\n" + "SavingAccount (" +
                "annualInterestRate = " + annualInterestRate +
                ")";
    }

}