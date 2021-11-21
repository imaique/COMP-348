public class Circle implements Shape {
    private double radius;

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }
    public Circle(double radius){
        this.radius= radius;
    }

    @Override
    public String toString() {
        return getShapeName() + ", " + radius;
    }
    public static Circle parse(String input){
        String[] splitInput = input.split(",");
        // prob not necessary since i decide if it goes in parse or not
        // if (splitInput[0].compareToIgnoreCase("rectangle")!=0) throw new InvalidClassException("The input to be parsed does not start with Rectangle.");

        return new Circle(Double.parseDouble(splitInput[1]));
    }

    @Override
    public double getShapePerimeter() {
        return 2 * Math.PI * radius;
    }

    @Override
    public double getShapeArea() {
        return Math.PI * radius * radius;
    }

    @Override
    public String getShapeName() {
        return Shape.super.getShapeName().toUpperCase();
    }
}
