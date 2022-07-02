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
public abstract class Goods implements Item {

@Override
public JenisItem jenis() {
return new Send();
}

@Override
public abstract float price();
}