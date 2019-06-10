<?php
function detailed_img_info($id)
{
	include('../config/database.php');
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("SELECT login FROM montages WHERE id_montage = ?;");
		$stmt->bindValue(1, $id, PDO::PARAM_STR);
		$stmt->execute();
		$result = $stmt->fetch(PDO::FETCH_ASSOC);
		$stmt->closeCursor();
	}
	catch (PDOException $ex)
	{
		$_SESSION['message'] = "Error: Could not reach the database";
		return($ex);
	}
	return($result);
}

function nb_likes($id)
{
	include('../config/database.php');
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("SELECT auteur FROM likes WHERE id_montage = ?;");
		$stmt->bindValue(1, $id, PDO::PARAM_STR);
		$stmt->execute();
		$result = $stmt->fetchAll(PDO::FETCH_ASSOC);
		$stmt->closeCursor();
	}
	catch (PDOException $ex)
	{
		$_SESSION['message'] = "Error: Could not reach the database";
		return($ex);
	}
	return(count($result));
}

function nb_comments($id)
{
	include('../config/database.php');
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("SELECT auteur FROM comments WHERE id_montage = ?;");
		$stmt->bindValue(1, $id, PDO::PARAM_STR);
		$stmt->execute();
		$result = $stmt->fetchAll(PDO::FETCH_ASSOC);
		$stmt->closeCursor();
	}
	catch (PDOException $ex)
	{
		$_SESSION['message'] = "Error: Could not reach the database";
		return($ex);
	}
	return(count($result));
}

function is_liked($id, $auteur)
{
	include('../config/database.php');
	try
	{
		$pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
		$pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		$stmt = $pdo->prepare("SELECT auteur FROM likes WHERE id_montage = ? AND auteur = ?;");
		$stmt->bindValue(1, $id, PDO::PARAM_STR);
		$stmt->bindValue(2, $auteur, PDO::PARAM_STR);
		$stmt->execute();
		$result = $stmt->fetchAll(PDO::FETCH_ASSOC);
		$stmt->closeCursor();
	}
	catch (PDOException $ex)
	{
		$_SESSION['message'] = "Error: Could not reach the database";
		return($ex);
	}
	if (count($result) > 0)
		return("clicked");
	else
		return("");
}

?>
