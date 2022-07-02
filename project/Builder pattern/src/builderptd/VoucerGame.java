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
public abstract class VoucerGame implements Item {

@Override
public JenisItem jenis() {
return new Online();
}

@Override
public abstract float price();
}