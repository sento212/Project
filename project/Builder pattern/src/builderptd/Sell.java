/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package builderptd;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author ACER
 */
public class Sell {
private List<Item> items = new ArrayList<Item>();

public void addItem(Item item){
items.add(item);
}

public float getCost(){
float cost = 0.0f;
float discound = 20;
for (Item item : items) {
cost += item.price();
if( "Fresh tea".equals(item.name())){
  cost = (item.price() * discound)/100;
  cost = item.price() - cost;
}
}
return cost;
}

public void showItems(){
  float discound = 20;
for (Item item : items) {
    
System.out.println("JenisItem : "+item.jenis().Jenis());    
System.out.println("Item : "+item.name());
System.out.println("Price : "+item.price());
if("Fresh tea".equals(item.name())){
    System.out.println("Diskon "+discound+"%");
}
    System.out.println("");
}
}
}