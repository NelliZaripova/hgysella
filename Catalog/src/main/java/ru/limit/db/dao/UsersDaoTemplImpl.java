package ru.limit.db.dao;

import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import ru.limit.db.model.User;

import javax.sql.DataSource;
import java.sql.ResultSet;
import java.util.HashMap;
import java.util.Map;
import java.util.List;
import java.util.Optional;

public class UsersDaoTemplImpl implements UsersDao {

    private JdbcTemplate template;

    //language=SQL
    private final String SQL_SELECT_ALL =
            "SELECT * FROM users_bd";


    private Map<Integer, User> userMap = new HashMap<>();


    private final String SQL_SELECT_ALL_BY_FIRST_NAME =
            "SELECT * FROM users_bd WHERE first_name = ?";

    private final String  SQL_DELETE_BY_ID =
            "DELETE FROM users_bd WHERE id = ?";

    public UsersDaoTemplImpl(DataSource dataSource){
        this.template = new JdbcTemplate(dataSource);
    }

    private RowMapper<User> userRowMapper
            = (ResultSet resultSet, int i) -> {
        return new User(
                resultSet.getInt("id"),
                resultSet.getString("login"),
                resultSet.getString("first_name"),
                resultSet.getString("last_name"),
                resultSet.getString("address"));
     };

    @Override
    public List<User> findAllByFirstName(String firstName) {
        return template.query(SQL_SELECT_ALL_BY_FIRST_NAME, userRowMapper, firstName);
    }

    @Override
    public Optional<User> find(Integer id) {
        if (userMap.containsKey(id)) {
            return Optional.of(userMap.get(id));
        }
        return Optional.empty();
    }

    @Override
    public void save(User model) {
    }

    @Override
    public void update(User model) {
    }

    @Override
    public void delete(Integer id) {
        template.query(SQL_DELETE_BY_ID, userRowMapper);
    }

    @Override
    public List<User> findAll() {
        return template.query(SQL_SELECT_ALL, userRowMapper);
    }
}
