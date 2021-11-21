class Ellipse < Shape

  def initialize (a, b)
    super()
    if (a<b)
      @a = b
      @b = a
    else
      @a = a
      @b = b
    end
  end

  def area
    if (@a < 0 || @b < 0)
      return nil
    end

    return Math::PI * @a * @b
  end

  def eccentricity
    #when to return nil?????????
    return Math::sqrt(@a*@a-@b*@b)
  end
end