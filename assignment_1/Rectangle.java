import java.io.InvalidClassException;

public class Rectangle implements Shape {
    private double height;
    private double width;

    public double getWidth() {
        return width;
    }

    public double getHeight() {
        return height;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public Rectangle(double height, double width) {
        this.width = width;
        this.height = height;
    }

    // what if input null or something
    public static Rectangle parse(String input){
        String[] splitInput = input.split(",");
        // Useless because we decide if it calls this method or not.
        // if (splitInput[0].compareToIgnoreCase("rectangle")!=0) throw new InvalidClassException("The input to be parsed does not start with Rectangle.");

        return new Rectangle(Double.parseDouble(splitInput[1]),Double.parseDouble(splitInput[2]));
    }

    //maybe specify the side
    @Override
    public String toString() {
        return getShapeName() + ", " + height + ", " + width;
    }

    @Override
    public double getShapePerimeter() {
        return width*2 + height*2;
    }

    @Override
    public double getShapeArea() {
        return width*height;
    }
}
