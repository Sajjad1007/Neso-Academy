package neso;

//A class to create rectangles of real world
public class Rectangle extends GeoObject implements Drawable {

    //Both attributes are initialized to zero
    private double width;
    private double height;

    public Rectangle() {
        this(1, 1);
    } //superclass constructor are not invoked automatically

    public Rectangle(double width, double height) {
        this(true, "black", width, height);
    }

    public Rectangle(boolean isFilled, String color, double width, double height) {
        super(isFilled, color);
        this.width = width;
        this.height = height;
    }

    //Overriding the abstract getArea() method of "GeoObject" class
    @Override
    public double getArea() {
        return width * height;
    }

    //Overriding the abstract draw() method of "Drawable" interface
    @Override
    public void draw() {
        System.out.println("Drawing rectangle with width " + width + " and height " + height);
    }

    //Overriding the toString() method of "GeoObject" class
    @Override
    public String toString() {
        return "Rectangle { " +
                "width = " + width +
                ", height = " + height + " }";
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

}