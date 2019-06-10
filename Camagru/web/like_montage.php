<?php
session_start();
include ('../config/database.php');
try
{
	$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
	$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$stmt = $pdo->prepare("SELECT auteur FROM likes WHERE id_montage = ?;");
	$stmt->bindValue(1, $_POST['id'], PDO::PARAM_STR);
	$stmt->execute();
	$result = $stmt->fetchAll(PDO::FETCH_ASSOC);
	$stmt->closeCursor();

	if (!is_liked($result))
	{
		$stmt2 = $pdo->prepare("INSERT INTO likes (id_montage, auteur) VALUES (?, ?);");
		$stmt2->bindValue(1, $_POST['id'], PDO::PARAM_STR);
		$stmt2->bindValue(2, $_SESSION['user']['login'], PDO::PARAM_STR);
		$stmt2->execute();
		$stmt2->closeCursor();
		echo (count($result) + 1);
	}
	
	else
	{
		$stmt3 = $pdo->prepare("DELETE FROM likes WHERE id_montage = ? AND auteur = ?;");
		$stmt3->bindValue(1, $_POST['id'], PDO::PARAM_STR);
		$stmt3->bindValue(2, $_SESSION['user']['login'], PDO::PARAM_STR);
		$stmt3->execute();
		$stmt3->closeCursor();
		echo (count($result) - 1);
	}
}
catch (PDOEXCEPTION $ex)
{
	return (1);
}

function is_liked($result)
{
	foreach ($result as $elem)
	{
		if (in_array($_SESSION['user']['login'], $elem))
			return (true);
	}
	return (false);
}

?>
