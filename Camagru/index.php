<?php
include('config/database.php');
include('web/user.php');
try
{
	$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	unset($_SESSION['message']);
    header('location:http://127.0.0.1:8080/camagru/web/login.php');
}
catch (PDOException $ex)
{
	echo "Creation de la base de donnee, veuillez patienter <br />";
	include('config/setup.php');
	echo "<br />Veuillez rafraichir la page";
}
?>
