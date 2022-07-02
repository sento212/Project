package edu.ftiuksw.testapi;

import com.google.gson.annotations.Expose;
import com.google.gson.annotations.SerializedName;

public class Pegawai {
    @SerializedName("id")
    @Expose
    private String id;

    @SerializedName("salary")
    @Expose
    private String salary;

    @SerializedName("name")
    @Expose
    private String name;

    public Pegawai(String id, String salary, String name) {
        this.id = id;
        this.salary = salary;
        this.name = name;
    }

    public String getNim() {
        return id;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getSalary() {
        return salary;
    }

    public void setSalary(String salary) {
        this.salary = salary;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }


}
