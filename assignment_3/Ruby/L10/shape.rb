class Shape
  @@current = 1;

  def getid
    return @id
  end

  def initialize
    @id = @@current
    @@current += 1
  end

  def print
    perim_s = perimeter

    perim_s = if perim_s.nil? then 'undefined'
            else
              format('%.5f', perim_s)
            end
    area_s = area

    area_s = if area_s.nil? then 'undefined'
             else
               format('%.5f', area_s)
             end

    puts "#{getid}: " + self.class.to_s + ", perimeter: #{perim_s}, area: #{area_s}"
  end

  def perimeter
    nil
  end

  def area
    nil
  end
end