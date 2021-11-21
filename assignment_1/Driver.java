
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.*;
import java.util.stream.Stream;

public class Driver {
    public static void main(String[] args) {

        Scanner keyboardInput = new Scanner(System.in);
        System.out.print("Please enter the name of the file containing the shapes: ");
        //String fileName = keyboardInput.nextLine();
        String fileName = "shapes.txt";
        List<Shape> shapeList = new ArrayList<>();


        // Reading the file
        try (Stream<String> stream =  Files.lines(Path.of(fileName))){
            stream.forEach( e-> {
                // Split the line and save the name.
                String[] line = e.split(",");
                String shapeName = line[0];

                // Check what is the name of the given shape, create the corresponding Shape and add it to the list.
                if (shapeName.equalsIgnoreCase("rectangle"))
                    shapeList.add(Rectangle.parse(e));
                else if (shapeName.equalsIgnoreCase("circle"))
                    shapeList.add(Circle.parse(e));
                else System.err.println("Invalid shape, skipping to the next line.");
                    }
            );




            System.out.println("\nSorting and displaying the shapes by shape name and area: ");
            Collections.sort(shapeList,
                    (s1,s2) -> {
                        int nameCompare = s1.getShapeName().compareToIgnoreCase(s2.getShapeName());
                        if (nameCompare!=0) return nameCompare;
                        return (int)(s1.getShapeArea() - s2.getShapeArea());
                    });
            // method reference
            shapeList.forEach(System.out::println);

            System.out.println("\nSorting and displaying the shapes by perimeter only: ");
            Collections.sort(shapeList,
                    (s1,s2) ->{
                        return (int)(s1.getShapePerimeter() - s2.getShapePerimeter());
                    });
            shapeList.forEach(System.out::println);
            System.out.println();





            double circleAvgPerimeter = shapeStream("circle",shapeList).mapToDouble(s -> s.getShapePerimeter()).average().getAsDouble();
            double circleAvgArea = shapeStream("circle",shapeList).mapToDouble(s -> s.getShapeArea()).average().getAsDouble();



            double rectangleAvgPerimeter = shapeStream("rectangle",shapeList).mapToDouble(s -> s.getShapePerimeter()).average().getAsDouble();
            double rectangleAvgArea = shapeStream("rectangle",shapeList).mapToDouble(s -> s.getShapeArea()).average().getAsDouble();

            System.out.println("The circles' average perimeter is " + circleAvgPerimeter +", and their average area is " + circleAvgArea + ".");
            System.out.println("The rectangles' average perimeter is " + rectangleAvgPerimeter +", and their average area is " + rectangleAvgArea + ".");

            double avgPerimeter = shapeList.stream().mapToDouble(s -> s.getShapePerimeter()).average().getAsDouble();
            double avgArea = shapeList.stream().mapToDouble(s -> s.getShapeArea()).average().getAsDouble();

            System.out.println("\nThe total average perimeter and average is " + avgPerimeter + " and " + avgArea + ", respectively, and there is a total of " + shapeList.size() + " shapes.");


        }catch (IOException e){
            System.err.println("io exception");
        }


    }
    public static Stream<Shape> shapeStream(String shapeName, List<Shape> shapeList){
        return shapeList.stream().filter(
                s -> s.getShapeName()
                        .equalsIgnoreCase(shapeName));
    }
}
