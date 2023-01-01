import Dohoa.*;


public class TestShape {
    
    public static void main(String[] args) {
        Square square = new Square(5);
        System.out.println(square.toString());
        System.out.println(square.calcArea());
        System.out.println(square.calcPerimeter());
        square.draw();


        Rectangle rectangle = new Rectangle(10, 5);

        System.out.println(rectangle.toString());
        System.out.println(rectangle.calcArea());
        System.out.println(rectangle.calcPerimeter());
        rectangle.draw();

    }



}
