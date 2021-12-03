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
public class SellBuilder {

public Sell prepareOnline (){
Sell sell = new Sell();
sell.addItem(new Genshin());
sell.addItem(new MobileLegend());
return sell;
}

public Sell prepareOfline (){
Sell sell = new Sell();
sell.addItem(new Tea());
sell.addItem(new Cheatos());
sell.addItem(new Under5Kg());
sell.addItem(new Sapu());
sell.addItem(new Indomie());
return sell;
}

}
