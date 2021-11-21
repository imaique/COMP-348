public interface Shape {
    default String getShapeName(){
        return this.getClass().getSimpleName();
    }
    double getShapePerimeter();
    double getShapeArea();
}
