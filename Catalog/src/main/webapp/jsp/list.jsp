<%--
  Created by IntelliJ IDEA.
  User: hgysella
  Date: 2019-05-06
  Time: 14:36
  To change this template use File | Settings | File Templates.
--%>
<%@ taglib uri = "http://java.sun.com/jsp/jstl/core" prefix = "c" %>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>


<html>
<head>
    <title>Users</title>
    <link href="/css/styles.css" rel="stylesheet" type="text/css">
</head>
<body>
    <div>
        <div>
            <h3>List Users</h3>
        </div>
        <table>
            <form method="post">
            <tr>
                <th>Login</th>
                <th>First name</th>
                <th>Last Name</th>
            </tr>
            <c:forEach items="${usersFromServer}" var="user">
                <tr>

                    <td><a title="click for more info" href="/userinfo">${user.login}</a></td>
                    <td>${user.firstName}</td>
                    <td>${user.lastName}</td>
                    <td><button type="submit" name="delete" value="${user.id}">Delete user</button></td>
                    <td><button tupe="submit" name="update" value="${user.id}">Update Info</button></td>
                </tr>
            </c:forEach>
        </table>
        </form>
    </div>


<%--  форма для добавления  --%>
    <div>
        <br>
        <h3>Add User</h3>
        <form method="post">
            <table>
                <tr>
                    <td>
                        <label for="login">Login
                            <input type="text" id="login" name="login">
                        </label>
                    </td>
                    <td>
                        <label for="firstName">First name
                            <input type="text" id="firstName" name="firstName">
                        </label>
                    </td>
                    <td>
                        <label for="lastName">Last name
                            <input type="text" id="lastName" name="lastName">
                        </label>
                    </td>
                </tr>
                <tr>
<%--                    <td>--%>
<%--                        <label for="birthDate">Birth date--%>
<%--                            <input type="date" id="birthDate" name="birthDate">--%>
<%--                        </label>--%>
<%--                    </td>--%>
                    <td>
                        <label for="address">Address
                            <input type="text" id="address" name="address">
                        </label>
                    </td>
                    <td>
                        <label for="info">Additional Information
                            <input type="text" id="info" name="info">
                        </label>
                    </td>
                </tr>
<%--                <tr>--%>
<%--                    <td>--%>
<%--                        <label for="role">Role--%>
<%--                            <input type="text" id="role" name="role">--%>
<%--                        </label>--%>
<%--                    </td>--%>
<%--                    <td>--%>
<%--                        <label for="photo">Photo--%>
<%--                            <input type="text" id="photo" name="photo">--%>
<%--                        </label>--%>
<%--                    </td>--%>
<%--                </tr>--%>
            </table>
            <button tupe="submit" name="add" value="add">Add user to list</button>
        </form>
    </div>
</body>
</html>

