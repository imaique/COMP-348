public privileged aspect ShapeParent {
    declare parents: Circle implements Shape;
    declare parents: Rectangle implements Shape;
    declare parents: Circle implements Identifiable;
    declare parents: Rectangle implements Identifiable;

    int Circle.Id;
    int Rectangle.Id;

    public int Circle.getId(){
        return this.Id;
    }
    public int Rectangle.getId(){
        return this.Id;
    }

    private static int counter = 0;

    after(Rectangle r) : execution(Rectangle.new(..)) && this(r){
        r.Id = counter;
        counter++;
    }

    after(Circle c) : execution(Circle.new(..)) && this(c){
        c.Id = counter;
        counter++;
    }


    public String Circle.getName(){
        return "Circle";
    }
    public String Rectangle.getName(){
        return "Rectangle";
    }

    public String Circle.toString() {
        return this.getName() + "(" + radius + ")";
    }

    public String Rectangle.toString() {
        return this.getName() + "(" + width + ", " + height + ")";
    }

    pointcut getArea(Circle c) : execution(double Circle.getArea()) && this(c);

    pointcut circleGetters(Circle c) : (execution(double Circle.getArea()) || execution(double Circle.getPerimeter())) && this(c);

    pointcut rectangleGetters(Rectangle r) : (execution(double Rectangle.getArea()) || execution(double Rectangle.getPerimeter())) && this(r);

    double around(Circle circle) : getArea(circle){
        return Math.PI * circle.radius * circle.radius;
    }

    double around(Circle circle) : circleGetters(circle){
        if (circle.radius<=0) return 0;
        else return proceed(circle);
    }

    double around(Rectangle r) : rectangleGetters(r){
        if(r.width<=0 || r.height<=0) return 0;
        else return proceed(r);
    }

    //pointcut handleNegative(Shape s) : execution(double Shape.getArea()) double Shape.getPerimeter()) && this(s);

    //int around(Circle circle) :
}
