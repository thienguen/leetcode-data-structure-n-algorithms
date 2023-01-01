package Dohoa;

public abstract class Shape {
    private String name;
    private boolean filled;

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public boolean isFilled() {
        return this.filled;
    }

    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    public void draw() {
        System.out.println("Ve hinh shape");
    }

    abstract public double calcArea();

    abstract public double calcPerimeter();
}
