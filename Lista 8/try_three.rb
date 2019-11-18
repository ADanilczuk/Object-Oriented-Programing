=begin
	Alicja Danilczuk
	Pracownia PO, czwartek, s. 108
	L8, z3
	Klasa
	2018-04-19
=end
 
 # Klasa przechowująca napis zawierająca metodę szyfrującą
class Jawna
	
	# Konstruktor
	def initialize (napis)
	@napis = napis
	end
	
	def zaszyfruj(klucz)
	z = ""
	i = 0
	while i < @napis.length
	z += klucz[@napis[i]]
	i += 1
	end
	# Zwracamy obiekt klasy Zaszyfrowana (zaszyfrowany napis)
	return Zaszyfrowana.new(z)
	end
	
	# Metoda która mówi interpreterowi, że @napis 
	# ma odczytać jako string
	def to_s
	@napis
	end
end 

 # Klasa przechowująca napis zawierająca metodę deszyfrującą
class Zaszyfrowana 

	# Konstruktor
	def initialize (napis)
	@napis = napis
	end
	
	def odszyfruj(klucz)
	z=""
	i=0
	while i < @napis.length
	z += klucz.key(@napis[i])
	i += 1
	end
	# Zwracamy obiekt klasy Jawna (odszyfrowany napis)
	return Jawna.new(z)
	end
	
	# Metoda która mówi interpreterowi, że @napis 
	# ma odczytać jako string
	def to_s
	@napis
	end
end


# Testy 

# Zapisujemy klucz szyfrujący
klucz = {"a" => "b" , "b" => "c", "c" => "d", "d" => "e", "e" => "f", "f" => "g"}



x= Jawna.new("abce")
puts x
zasz = x.zaszyfruj(klucz)
puts zasz
puts zasz.odszyfruj(klucz)
	