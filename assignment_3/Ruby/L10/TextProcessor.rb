load 'shape.rb'
load 'circle.rb'
load 'rhombus.rb'
load 'ellipse.rb'

def contains_invalid(array)
  array.each do |num|
    Integer(num)
    if num.to_i.negative?
      return true
    end
  end
  false
rescue ArgumentError
  true
end



object_count = { 'shape' => 0 }

File.open('shapes.txt').each do |line|
  arr = line.split(' ')
  numbers = arr[1..arr.length - 1]

  invalid = contains_invalid(numbers)

  unless arr[0] == 'shape'
    object_count[arr[0]] = if object_count.include?(arr[0])
                             object_count[arr[0]] + 1
                           else
                             1
                           end
  end

  object_count['shape'] = object_count['shape'] + 1

  if invalid then
    puts "Error: Invalid #{arr[0].capitalize()}"
  end


  case arr[0].downcase
  when 'shape'

    Shape.new.print

  when 'circle'

    Circle.new(arr[1].to_i).print

  when 'ellipse'
    ellipse = Ellipse.new(arr[1].to_i, arr[2].to_i)
    ellipse.print
    puts "\tlinear eccentricity: #{format('%.5f',ellipse.eccentricity.to_s)}" unless invalid

  when 'rhombus'
    rhombus = Rhombus.new(arr[1].to_i, arr[2].to_i)
    rhombus.print
    puts "\tin-radius: #{format('%.5f',rhombus.inradius.to_s)}" unless invalid
  end
end

puts "\nStatistics: "

shape = object_count['shape']
object_count.delete_if {|key, value| key == 'shape'}
sorted = object_count.sort_by {|key, value| key}
sorted.each do |entry|
  puts "\t#{entry[0].capitalize()}(s): #{entry[1]}"
end

puts "\t--\n\tShape(s): #{shape}"
