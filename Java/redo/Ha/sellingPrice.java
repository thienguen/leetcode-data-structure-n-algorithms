public class sellingPrice {
    
    public static void main(String[] args)
    {
        // varibale declaration(s)
        double listPrice, discount, tax;

        // could be adjustable
        listPrice = 0;
        discount  = 0;
        tax       = 0;

        // simple math
        double sellingPrice = ( listPrice - discount ) + tax;
        Double d = (double) (Math.round(sellingPrice * 10.00) / 10.00);
        // syout stream
        System.out.println("The selling price is : " + d);
    }
}
