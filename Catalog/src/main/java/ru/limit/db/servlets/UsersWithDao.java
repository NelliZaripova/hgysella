package ru.limit.db.servlets;

import org.springframework.jdbc.datasource.DriverManagerDataSource;
import ru.limit.db.dao.UsersDao;
import ru.limit.db.dao.UsersDaoTemplImpl;
import ru.limit.db.model.User;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.FileInputStream;
import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.time.LocalDate;
import java.util.List;
import java.util.Optional;
import java.util.Properties;

@WebServlet("/list")
public class UsersWithDao  extends HttpServlet {
    private UsersDao usersDao;

    private final String  SQL_DELETE_BY_ID =
            "DELETE FROM users_bd WHERE id = ?";

    private Connection connection;

    @Override
    public void init() throws ServletException {
        Properties properties = new Properties();
        DriverManagerDataSource dataSource =
                new DriverManagerDataSource();

        try {
            properties.load(new FileInputStream(getServletContext().getRealPath("/WEB-INF/classes/db.properties")));
            String dbUrl = properties.getProperty("db.url");
            String dbUsername = properties.getProperty("db.username");
            String dbPassword = properties.getProperty("db.password");
            String driverClassName = properties.getProperty("db.driverClassName");

            dataSource.setUsername(dbUsername);
            dataSource.setPassword(dbPassword);
            dataSource.setUrl(dbUrl);
            dataSource.setDriverClassName(driverClassName);

            usersDao = new UsersDaoTemplImpl(dataSource);
        } catch (IOException e) {
            throw new IllegalArgumentException(e);
        }
    }

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException{
        Optional<User> user = usersDao.find(1);
        int i = 0;

        List<User> users = null;
        if (req.getParameter("firstName") != null) {
            String firstName = req.getParameter("firstName");
        }
        else {
            users = usersDao.findAll();
        }
        req.setAttribute("usersFromServer", users);
        req.getServletContext().getRequestDispatcher("/jsp/list.jsp").forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        String delete = req.getParameter("delete");
        System.out.println(delete);
        String add = req.getParameter("add");
        System.out.println(add);
        if (delete != null && add == null) {
            try {
                PreparedStatement statement = connection.prepareStatement(SQL_DELETE_BY_ID);
                statement.setInt(1, Integer.valueOf(delete));
                statement.execute();
            }catch (SQLException e)
            {
                throw new IllegalStateException(e);
            }
        }

        if (delete == null && add != null) {
            String login = req.getParameter("login");
            System.out.println(login);
            String firstName = req.getParameter("firstName");
            System.out.println(firstName);
            String lastName = req.getParameter("lastName");
            System.out.println(lastName);
            String address = req.getParameter("address");
            System.out.println(address);
            String info = req.getParameter("info");
            System.out.println(info);
            try {
                PreparedStatement preparedStatement =
                        connection.prepareStatement("INSERT INTO " +
                                "users_bd(login, first_name, last_name, address, info) VALUES (?, ?, ?, ?, ?)");
                preparedStatement.setString(1, login);
                preparedStatement.setString(2, firstName);
                preparedStatement.setString(3, lastName);
                preparedStatement.setString(4, address);
                preparedStatement.setString(5, info);
                preparedStatement.execute();
            } catch (SQLException e) {
                throw new IllegalStateException(e);
            }
        }
    }

}

//плохой вариант
//            Statement statement = connection.createStatement();
//            String sqlInsert = "INSERT INTO fix_user(first_name, last_name)" +
//                    "VALUES('" + firstName + "','" + lastName + "');";
//            System.out.println(sqlInsert);
//            statement.execute(sqlInsert);