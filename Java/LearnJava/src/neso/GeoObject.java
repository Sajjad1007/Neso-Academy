//This program illustrates the use of abstract classes in Java.

package neso;

//A class to create geometrical objects of real world
public abstract class GeoObject {

    private boolean isFilled; //initialized to false
    private String color; //initialized to null

    /*
    To have an empty constructor is a must for a superclass
    if there is no explicit call to superclass constructor with parameters in subclass constructor
    */
    protected GeoObject() {}

    //Though we can not instantiate a "GeoObject" object, but we need constructors in order to use them in subclass
    protected GeoObject(boolean isFilled, String color) {
        //The empty constructor of "Object" class will be called automatically
        this.isFilled = isFilled;
        this.color = color;
    }

    public abstract double getArea(); //abstract methods can not have a body

    //Overriding the toString() method of "Object" class
    @Override
    public String toString() {
        return "GeoObject { " +
                "isFilled = " + isFilled +
                ", color = " + color + " }";
    }

    public boolean isFilled() {
        return isFilled;
    }

    public void setFilled(boolean filled) {
        isFilled = filled;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

}