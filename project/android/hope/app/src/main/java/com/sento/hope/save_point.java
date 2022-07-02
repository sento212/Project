package com.sento.hope;

public class save_point {
    private String latitude;
    private String longtitude;

    public save_point() {
    }

    public save_point(String latitude, String longtitude) {
        this.latitude = latitude;
        this.longtitude = longtitude;
    }

    public String getLatitude() {
        return latitude;
    }

    public void setLatitude(String latitude) {
        this.latitude = latitude;
    }

    public String getLongtitude() {
        return longtitude;
    }

    public void setLongtitude(String longtitude) {
        this.longtitude = longtitude;
    }
}
