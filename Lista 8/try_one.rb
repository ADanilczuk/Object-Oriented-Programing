=begin
	Alicja Danilczuk
	Pracownia PO, czwartek, s. 108
	L8, z1
	Klasa
	2018-04-19
=end

class Fixnum
  
  # Metoda wypisująca wszystkie czynniki podanej liczby
  def czynniki
    i = 1
    odp = []
    while self >= i
      if self % i == 0
        odp += [i]
      end 
      i = i + 1 
    end
    return odp
  end
  
  # Metoda obliczająca wynik funkcji Ackermanna dla podanych liczb
  def ack(m)
    n = self 
    if n == 0
      return m + 1 
    elsif m == 0 
      n = n-1
     return n.ack(1)
    else 
     return (n-1).ack(n.ack(m-1))
    end
  end
  
  
  # Metoda sprawdzająca czy liczba jest doskonała
  def doskonala
    tab = self.czynniki
    i = 0
    dlugosc = tab.length 
    suma = 0
    while i < dlugosc - 1
      suma = suma + tab[i]
      i = i + 1
    end
    if suma == self
      return true
    else
      return false
    end
  end
    
    
  # Metoda wypisująca słownie wszystkie cyfry podanej liczby 
  def slownie
    tab = self.to_s 
    odp = ""
    i = 0
  while i < tab.length 
    case tab[i]
    when "0"
      odp += "zero "
    when "1" 
      odp += "jeden "
    when "2" 
      odp += "dwa "
    when "3" 
      odp += "trzy "
    when "4" 
      odp += "cztery "
    when "5" 
      odp += "pięć "
    when "6" 
      odp += "sześć "
    when "7"
      odp += "siedem "
    when "8"
      odp += "osiem "
    when "9" 
      odp += "dziewięć "
    end
    i = i + 1 
  end
  return odp
  end
      
end

puts ""

# Wszystkie czynniki liczby 8
a = 0
puts a.czynniki

# Wynik funkcji Ackermanna dla n=2 i m=1
x = 2   
 puts  x.ack(1)
 
# Sprawdzenie czy 9 jest liczbą doskonałą
puts  9.doskonala
# Sprawdzenie czy 6 jest liczbą doskonałą
puts  6.doskonala

# Wypisanie słownie wszystkich cyfr liczby 876
puts 876.slownie


