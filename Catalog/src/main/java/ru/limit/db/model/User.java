package ru.limit.db.model;

import javax.xml.soap.Text;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class User {
    private Integer id;
    private String login;
    private String firstName;
    private String lastName;
    private LocalDate birth_date;
    private String adress;
    private Text info;
    private String role;


    public User(String login, String firstName, String lastName) {
        this.login = login;
        this.firstName = firstName;
        this.lastName = lastName;
    }

    public User(Integer id, String login, String firstName, String lastName, String adress) {
        this.id = id;
        this.login = login;
        this.firstName = firstName;
        this.lastName = lastName;
        this.adress = adress;
    }

    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getLogin() {
        return login;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public LocalDate getBirth_date() {
        return birth_date;
    }

    public void setBirth_date(LocalDate birth_date) {
        this.birth_date = birth_date;
    }

    public String getAdress() {
        return adress;
    }

    public void setAdress(String adress) {
        this.adress = adress;
    }

    public Text getInfo() {
        return info;
    }

    public void setInfo(Text info) {
        this.info = info;
    }

    public String getRole() {
        return role;
    }

    public void setRole(String role) {
        this.role = role;
    }
}
