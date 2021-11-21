
class Rhombus < Shape
  def initialize (p, q)
    super()
    @p = p
    @q = q
  end

  def perimeter
    if (@p < 0 || @q < 0)
      return nil
    end
    if @p.zero? then return @q*2
    end
    if @q.zero? then return @p*2
    end


    a = @p/2
    b = @q/2
    c = Math::sqrt(a * a + b * b)
    return c*4
  end

  def area
    if (@p < 0 || @q < 0)
      return nil
    end
    return (@p*@q)/2
  end

  def inradius

    return (@p*@q)/(2 * Math::sqrt(@p*@p + @q*@q))
  end
end