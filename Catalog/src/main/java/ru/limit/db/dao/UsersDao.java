package ru.limit.db.dao;

import ru.limit.db.model.User;

import java.util.List;

public interface UsersDao extends CrudDao<User> {
    List<User> findAllByFirstName(String firstName);
}
