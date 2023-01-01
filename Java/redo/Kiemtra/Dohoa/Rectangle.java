package Dohoa;

public class Rectangle extends Shape {
    private int width;
    private int height;

    public Rectangle(int width, int height) {
        super();
        this.width = width;
        this.height = height;
    }

    public Rectangle() {
        super();
        this.width = 1;
        this.height = 1;
    }

    public Rectangle(int width, int height, boolean filled) {
        super();
        this.width = width;
        this.height = height;
    }

    @Override
    public double calcArea() {
        return this.width * this.height;
    }

    @Override
    public double calcPerimeter() {
        return this.width * 2 + this.height * 2;
    }

    @Override
    public void draw() {
        System.out.println("Ve hinh Rectangle\n");

        for (int i = 0; i < this.height; i++) {
            for (int j = 0; j < this.width; j++) {
                if (i == 0 || j == 0 || i == this.height - 1 || j == this.width - 1) {
                    System.out.print("*");
                } else {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
    }


    @Override
    public String toString() {
        return "RECT: " + this.getName() + " " + this.isFilled() + " " + this.width + " " + this.height;
    }


    public int getWidth() {
        return this.width;
    }

    public void setWidth(int width) {
        this.width = width;
    }


    public int getHeight() {
        return this.height;
    }


    public void setHeight(int height) {
        this.height = height;
    }

}