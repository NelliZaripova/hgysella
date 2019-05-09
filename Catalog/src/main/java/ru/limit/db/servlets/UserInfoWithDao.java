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
import java.util.List;
import java.util.Optional;
import java.util.Properties;

@WebServlet("/userinfo")
public class UserInfoWithDao extends HttpServlet {
    private UsersDao usersDao;

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
        req.getServletContext().getRequestDispatcher("/jsp/userinfo.jsp").forward(req, resp);
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        Optional<User> user = usersDao.find(1);
        int i = 0;

        List<User> users = null;
        if (req.getParameter("id") != null) {
            String id = req.getParameter("id");
        }
        else {
            users = usersDao.findAll();
        }
        req.setAttribute("usersFullInfo", users);
        req.getServletContext().getRequestDispatcher("/jsp/userinfo.jsp").forward(req, resp);
    }
}
