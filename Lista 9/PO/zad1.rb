class Funkcja

  # Konstruktor
  def initialize (&block)
      @function = block
  end

  # Obliczanie wartosc funkcji w punkcie x 
  def wartosc (x)   
    @function.call x
  end

  # Obliczanie wartosci pochodnej w punkcie x 
  def pochodna (x)  
    $h = 1.0e-10
    return (wartosc(x + $h) - wartosc(x)) / $h 
  end
  
  def zerowe (a, b, e)  # miejsca zerowe w przedziale od a do b z dokladnoscia e
    ((-e...e) === wartosc(a) and return a) or ((-e...e) === wartosc(b) and return b)

    middle = (a + b) / 2.0 # obliczam msrodek przedzialu i bede szedl i na lewo i na prawo

    (-e...e) === wartosc(middle) and return middle

    (wartosc(a) * wartosc(middle) < 0 and zerowe(a, middle, e)) or (wartosc(b) * wartosc(middle) < 0 and zerowe(middle, b, e)) or nil
	
	
  end


  def pole (a, b)
  
    area = 0.0
    $n = 1000
    @dx = (b - a) / $n.to_f

    $n.times { |x| area += @dx * wartosc( a + x * @dx) } # n razy wykonaj znowu przybliz wartosc

    return area
  end




end
if __FILE__ == $0
  f = Funkcja.new { |x| x * -2 + 5 }
  puts f.wartosc(3)
  puts f.pochodna(3)
  puts f.pole( -1, 1 )
  puts f.zerowe( -5, 5, 0.001 )
  puts f.zerowe( 0, 3, 0.00001 )

end
