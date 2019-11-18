// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L6, z1
// Klasa
// 2018-04-12

import java.io.Serializable;

// Klasa tworz¹ca element listy
// wyorzystuj¹ca interfejs Serializable
	@SuppressWarnings("serial")
	class Element<T> implements Serializable
	{
	    public T values;
	    public Element<T> next;
	    public Element<T> prev;
	    
	    public Element(){}
	
	    // Konstruktor przypisuj¹cy elementowi przesy³an¹ wartoœæ 
	    public Element (T obiekt)
	    {
	        this.values = obiekt;
	        this.next = null;
	        this.prev = null;
	    }
    }