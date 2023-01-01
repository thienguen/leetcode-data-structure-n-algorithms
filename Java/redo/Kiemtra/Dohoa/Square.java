package Dohoa;

public class Square extends Shape
{
    private int side;

    public int getSide() {
        return this.side;
    }

    public void setSide(int size) {
        this.side = size;
    }

    public Square(int side) {
        super();
        this.side = side;
    }

    public Square() {
        super();
        this.side = 1;
    }

    public Square(int size, boolean filled) {
        super();
        this.side = size;
    }

    @Override
    public double calcArea() {
        return this.side * this.side;
    }

    @Override
    public double calcPerimeter() {
        return this.side * 4;
    }

    @Override
    public void draw() {
        System.out.println("Ve hinh Square\n");

        for (int i = 0; i < this.side; i++) {
            for (int j = 0; j < this.side; j++) {
                if (i == 0 || j == 0 || i == this.side - 1 || j == this.side - 1) {
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
        return "SQR: " + this.getName() + " " + this.isFilled() + " " + this.getSide();
    }
}