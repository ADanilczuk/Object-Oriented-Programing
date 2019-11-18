// Alicja Danilczuk
// Pracownia PO, czwartek, s. 108
// L6, z1
// Klasa
// 2018-04-12

import java.io.Serializable;

// Klasa tworz�ca element listy
// wyorzystuj�ca interfejs Serializable
	@SuppressWarnings("serial")
	class Element<T> implements Serializable
	{
	    public T values;
	    public Element<T> next;
	    public Element<T> prev;
	    
	    public Element(){}
	
	    // Konstruktor przypisuj�cy elementowi przesy�an� warto�� 
	    public Element (T obiekt)
	    {
	        this.values = obiekt;
	        this.next = null;
	        this.prev = null;
	    }
    }