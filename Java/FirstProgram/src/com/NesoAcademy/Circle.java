package com.NesoAcademy;

//this is a class to create circles of real world
public class Circle extends GeoObject implements Drawable {

    private double radius;

    public Circle() {
        this(1);
    }

    public Circle(double radius) {
        this(true, "black", radius);
    }

    public Circle(boolean isFilled, String color, double radius) {
        super(isFilled, color);
        this.radius = radius;
    }

    //overriding the abstract getArea() method of "GeoObject" class
    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }

    //overriding the abstract draw() method of "Drawable" interface
    @Override
    public void draw() {
        System.out.println("Drawing circle with radius " + radius);
    }

    //overriding the toString() method of "GeoObject" class
    @Override
    public String toString() {
        return "Circle { " +
                "radius = " + radius + " }";
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }

}
