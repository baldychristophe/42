<?php
session_start();

$ft_name = $_POST['ft_name'];
if ($ft_name == "save_webcam")
	save_webcam($_POST['fond']);
else if ($ft_name == "save_upload")
	save_upload($_POST['fond']);

function save_webcam($img) 
{
	include ('../config/database.php');
	include ('user.php');
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("INSERT INTO montages (login) VALUES (?);");
		$stmt->bindValue(1, $_SESSION['user']['login'], PDO::PARAM_STR);
		$stmt->execute();
		$lastId = $pdo->lastInsertId();
		$stmt->closeCursor();
	}
	catch (PDOException $ex)
	{
		return (1);
	}
	$new = fopen("../montages/id" . $lastId, "w");
	fwrite($new, $img);
	fclose($new);
}

?>
