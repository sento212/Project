/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package builderptd;

/**
 *
 * @author ACER
 */
public class BuilderPTD {
    public static void main(String[] args) {
 float total = 0.0f;
SellBuilder sellBuilder = new SellBuilder();
System.out.print("Toko Anugrah\n\n");

Sell onlineitem = sellBuilder.prepareOnline();
        System.out.println("Online");
onlineitem.showItems();
System.out.println("Total Cost: Rp "+onlineitem.getCost());
System.out.println("-------------------------------------------");

Sell offlineitem = sellBuilder.prepareOfline();
        System.out.println("Barang");
offlineitem.showItems();
System.out.println("Total Cost: Rp " +offlineitem.getCost());
System.out.println("-------------------------------------------");

total = onlineitem.getCost()+offlineitem.getCost();
System.out.println("\n\nTotal All : Rp "+total);
System.out.println("-------------------------------------------");
}
}
