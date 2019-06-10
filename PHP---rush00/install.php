<?php
if ($_POST['submit']){
  if (!($mysqli = mysqli_connect("163.172.134.147:3306", "ft_minishop","minishoppassword")))
    exit("Could not connect: ".mysqli_connect_error().PHP_EOL);
  if (!($queries = file_get_contents("install.sql")))
    exit("Could not import database.".PHP_EOL);
  if (!(mysqli_multi_query($mysqli, $queries)))
    echo "Could not create database.".PHP_EOL;
  else
    header('location:redirection.php');
  if (!(mysqli_close($mysqli)))
    echo "Could not close connection.".PHP_EOL;
}
?>

<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>Installation</title>
  </head>
  <body>
    <center>
    <form action="./install.php" method="post">
      <input type="submit" name="submit" value="Create Database" style="width:600px;">
    </form>
  </center>
  </body>
</html>
