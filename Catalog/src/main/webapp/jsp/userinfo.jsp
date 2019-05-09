<%--
  Created by IntelliJ IDEA.
  User: hgysella
  Date: 2019-05-08
  Time: 18:02
  To change this template use File | Settings | File Templates.
--%>
<%@ page contentType="text/html;charset=UTF-8" language="java" %>
<html>
<head>
    <title>UserInfo</title>
</head>
<body>
    <div>
        <div>
            <h3>User</h3>
        </div>
        <form method="post">
        <table>
            <tr>
                <th>Login</th>
                <th>First name</th>
                <th>Last Name</th>
                <th>Address</th>
                <th>Info</th>

            </tr>
            <c:forEach items="${userFullInfo}" var="user">
                <tr>
                    <td>${user.login}</td>
                    <td>${user.firstName}</td>
                    <td>${user.lastName}</td>
                    <td>${user.address}</td>
                    <td>${user.info}</td>
                </tr>
            </c:forEach>
        </table>
        </form>
    </div>
    <br>
    <a href="/list">Back To List Users</a>
</body>
</html>
