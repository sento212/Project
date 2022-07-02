package DAO;

public class Root {
    private String username;
    private String password;



    public Root() { }

    public Root(int no, String username, String password ,String nama,int no_telp) {

        this.username = username;
        this.password = password;

    }


     public String getusername() {
        return username;
    }

    public void setusername(String username) {
        this.username = username;
    }
    
     public String getpassword() {
        return password;
    }

    public void setpassword(String password) {
        this.password = password;
    }
    

}
