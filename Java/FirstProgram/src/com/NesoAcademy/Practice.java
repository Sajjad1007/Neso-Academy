package com.NesoAcademy;

//this program illustrates interfaces in Java
public class Practice {

    public static void main(String[] args) {
        Drawable rectangle = new Rectangle(3, 8);
        Drawable circle = new Circle(2);

        System.out.println();
        rectangle.draw();
        circle.draw();

        System.out.println();
        System.out.println(rectangle);
        System.out.println(circle);
    }

}
