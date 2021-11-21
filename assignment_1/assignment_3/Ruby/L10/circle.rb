class Circle < Shape

  def initialize (r)
    super()
    @radius = r
  end

  def perimeter
    if @radius < 0
      return nil
    end
    return 2 * Math::PI * @radius
  end

  def area
    if @radius < 0
      return nil
    end
    return Math::PI * @radius * @radius
  end

end